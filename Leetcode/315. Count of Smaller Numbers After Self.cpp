#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int original_idx;
} Element;

void mergeAndCount(Element* arr, int left, int mid, int right, int* count) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Element* L = (Element*)malloc(n1 * sizeof(Element));
    Element* R = (Element*)malloc(n2 * sizeof(Element));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int right_counter = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].original_idx] += right_counter;
            arr[k++] = L[i++];
        } else {
            right_counter++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].original_idx] += right_counter;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Element* arr, int left, int right, int* count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        mergeAndCount(arr, left, mid, right, count);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* count = (int*)calloc(numsSize, sizeof(int));
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].original_idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, count);

    free(arr);
    return count;
}