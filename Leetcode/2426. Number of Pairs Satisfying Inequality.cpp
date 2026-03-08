#include <stdio.h>
#include <stdlib.h>

void mergeAndCount(int* arr, int left, int mid, int right, int diff, long long* count, int* temp) {
    int i = left;
    int j = mid + 1;
    
    while (j <= right) {
        while (i <= mid && arr[i] <= arr[j] + diff) {
            i++;
        }
        *count += (i - left);
        j++;
    }

    i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int* arr, int left, int right, int diff, long long* count, int* temp) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, diff, count, temp);
    mergeSort(arr, mid + 1, right, diff, count, temp);
    mergeAndCount(arr, left, mid, right, diff, count, temp);
}

long long numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int diff) {
    int n = nums1Size;
    int* delta = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        delta[i] = nums1[i] - nums2[i];
    }

    long long count = 0;
    mergeSort(delta, 0, n - 1, diff, &count, temp);

    free(delta);
    free(temp);
    return count;
}