typedef struct {
    struct ListNode** arr;
    int size;
} Heap;

void swap(struct ListNode** a, struct ListNode** b){
    struct ListNode* t=*a; *a=*b; *b=t;
}

void heapify(Heap* h, int i){
    int smallest=i, l=2*i+1, r=2*i+2;
    if(l<h->size && h->arr[l]->val < h->arr[smallest]->val) smallest=l;
    if(r<h->size && h->arr[r]->val < h->arr[smallest]->val) smallest=r;
    if(smallest!=i){
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    Heap h;
    h.arr = (struct ListNode**)malloc(listsSize*sizeof(struct ListNode*));
    h.size=0;
    
    for(int i=0;i<listsSize;i++)
        if(lists[i]) h.arr[h.size++] = lists[i];
    
    for(int i=h.size/2-1;i>=0;i--) heapify(&h,i);
    
    struct ListNode dummy, *tail=&dummy;
    while(h.size){
        struct ListNode* min = h.arr[0];
        tail->next = min;
        tail = tail->next;
        
        if(min->next) h.arr[0] = min->next;
        else h.arr[0] = h.arr[--h.size];
        
        heapify(&h,0);
    }
    tail->next=NULL;
    return dummy.next;
}
