#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int y;
    int type;
    int x_start;
    int x_end;
} Event;

typedef struct {
    int count;
    double length;
} Node;

int* unique_x;
int unique_x_count;
Node* tree;

int cmp_int(const void* a, const void* b) {
    long long val_a = *(const int*)a;
    long long val_b = *(const int*)b;
    return (val_a > val_b) - (val_a < val_b);
}

int cmp_event(const void* a, const void* b) {
    const Event* ea = (const Event*)a;
    const Event* eb = (const Event*)b;
    if (ea->y != eb->y)
        return (ea->y > eb->y) - (ea->y < eb->y);
    return ea->type - eb->type;
}

int get_x_index(int val) {
    int l = 0, r = unique_x_count - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (unique_x[mid] == val) return mid;
        if (unique_x[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void update(int node, int start, int end, int l, int r, int val) {
    if (l > end || r < start) return;

    if (l <= start && end <= r) {
        tree[node].count += val;
    } else {
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
    }

    if (tree[node].count > 0) {
        tree[node].length = (double)unique_x[end + 1] - (double)unique_x[start];
    } else {
        if (start != end) {
            tree[node].length = tree[2 * node].length + tree[2 * node + 1].length;
        } else {
            tree[node].length = 0.0;
        }
    }
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    if (squaresSize == 0) return 0.0;

    int* x_coords = (int*)malloc(2 * squaresSize * sizeof(int));
    for (int i = 0; i < squaresSize; i++) {
        x_coords[2 * i] = squares[i][0];
        x_coords[2 * i + 1] = squares[i][0] + squares[i][2];
    }

    qsort(x_coords, 2 * squaresSize, sizeof(int), cmp_int);
    
    unique_x = (int*)malloc(2 * squaresSize * sizeof(int));
    unique_x_count = 0;
    if (squaresSize > 0) {
        unique_x[0] = x_coords[0];
        unique_x_count = 1;
        for (int i = 1; i < 2 * squaresSize; i++) {
            if (x_coords[i] != x_coords[i - 1]) {
                unique_x[unique_x_count++] = x_coords[i];
            }
        }
    }
    free(x_coords);

    Event* events = (Event*)malloc(2 * squaresSize * sizeof(Event));
    for (int i = 0; i < squaresSize; i++) {
        int x = squares[i][0];
        int y = squares[i][1];
        int l = squares[i][2];
        
        events[2 * i].y = y;
        events[2 * i].type = 1;
        events[2 * i].x_start = x;
        events[2 * i].x_end = x + l;
        
        events[2 * i + 1].y = y + l;
        events[2 * i + 1].type = -1;
        events[2 * i + 1].x_start = x;
        events[2 * i + 1].x_end = x + l;
    }
    qsort(events, 2 * squaresSize, sizeof(Event), cmp_event);

    int num_intervals = unique_x_count - 1;
    if (num_intervals <= 0) {
        free(unique_x);
        free(events);
        return 0.0;
    }
    
    tree = (Node*)calloc(4 * num_intervals, sizeof(Node));

    double total_area = 0.0;
    for (int i = 0; i < 2 * squaresSize; i++) {
        if (i > 0) {
            double h = (double)events[i].y - (double)events[i - 1].y;
            double w = tree[1].length;
            total_area += w * h;
        }
        
        int l_idx = get_x_index(events[i].x_start);
        int r_idx = get_x_index(events[i].x_end) - 1;
        
        if (l_idx <= r_idx) {
            update(1, 0, num_intervals - 1, l_idx, r_idx, events[i].type);
        }
    }

    for (int i = 0; i < 4 * num_intervals; i++) {
        tree[i].count = 0;
        tree[i].length = 0.0;
    }

    double target_area = total_area / 2.0;
    double current_area = 0.0;
    double result_y = 0.0;

    for (int i = 0; i < 2 * squaresSize; i++) {
        if (i > 0) {
            double h = (double)events[i].y - (double)events[i - 1].y;
            double w = tree[1].length;
            double strip_area = w * h;

            if (current_area + strip_area >= target_area) {
                double needed = target_area - current_area;
                double height_needed = (w > 1e-9) ? (needed / w) : 0.0;
                result_y = (double)events[i - 1].y + height_needed;
                break;
            }
            current_area += strip_area;
        }

        int l_idx = get_x_index(events[i].x_start);
        int r_idx = get_x_index(events[i].x_end) - 1;
        
        if (l_idx <= r_idx) {
            update(1, 0, num_intervals - 1, l_idx, r_idx, events[i].type);
        }
    }

    free(unique_x);
    free(events);
    free(tree);

    return result_y;
}