typedef struct {
    long long val;
    int prev;
    int next;
    bool active;
} Node;

typedef struct {
    long long sum;
    int index;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (HeapNode*)malloc(sizeof(HeapNode) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void push(MinHeap* h, long long sum, int index) {
    if (h->size == h->capacity) return;
    int i = h->size++;
    h->data[i].sum = sum;
    h->data[i].index = index;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].sum > h->data[i].sum || (h->data[p].sum == h->data[i].sum && h->data[p].index > h->data[i].index)) {
            swap(&h->data[p], &h->data[i]);
            i = p;
        } else {
            break;
        }
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int small = left;
        if (right < h->size) {
            if (h->data[right].sum < h->data[left].sum || (h->data[right].sum == h->data[left].sum && h->data[right].index < h->data[left].index)) {
                small = right;
            }
        }
        if (h->data[i].sum > h->data[small].sum || (h->data[i].sum == h->data[small].sum && h->data[i].index > h->data[small].index)) {
            swap(&h->data[i], &h->data[small]);
            i = small;
        } else {
            break;
        }
    }
    return root;
}

// Function name corrected to match LeetCode's main driver
int minimumPairRemoval(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    Node* nodes = (Node*)malloc(sizeof(Node) * numsSize);
    int bad_count = 0;
    MinHeap* pq = createHeap(numsSize * 4);

    for (int i = 0; i < numsSize; i++) {
        nodes[i].val = nums[i];
        nodes[i].prev = i - 1;
        nodes[i].next = (i == numsSize - 1) ? -1 : i + 1;
        nodes[i].active = true;
        
        if (i < numsSize - 1) {
            if (nums[i] > nums[i + 1]) bad_count++;
            push(pq, (long long)nums[i] + nums[i + 1], i);
        }
    }

    int ops = 0;

    while (bad_count > 0) {
        HeapNode top = pop(pq);
        int idx = top.index;

        if (!nodes[idx].active || nodes[idx].next == -1 || !nodes[nodes[idx].next].active) continue;
        
        long long current_pair_sum = nodes[idx].val + nodes[nodes[idx].next].val;
        if (current_pair_sum != top.sum) continue;

        int right = nodes[idx].next;
        int next_right = nodes[right].next;
        int prev = nodes[idx].prev;

        if (prev != -1 && nodes[prev].val > nodes[idx].val) bad_count--;
        if (nodes[idx].val > nodes[right].val) bad_count--;
        if (next_right != -1 && nodes[right].val > nodes[next_right].val) bad_count--;

        nodes[idx].val = current_pair_sum;
        nodes[idx].next = next_right;
        nodes[right].active = false;

        if (next_right != -1) nodes[next_right].prev = idx;

        if (prev != -1 && nodes[prev].val > nodes[idx].val) bad_count++;
        if (next_right != -1 && nodes[idx].val > nodes[next_right].val) bad_count++;

        if (prev != -1) push(pq, nodes[prev].val + nodes[idx].val, prev);
        if (next_right != -1) push(pq, nodes[idx].val + nodes[next_right].val, idx);

        ops++;
    }

    free(nodes);
    free(pq->data);
    free(pq);
    return ops;
}