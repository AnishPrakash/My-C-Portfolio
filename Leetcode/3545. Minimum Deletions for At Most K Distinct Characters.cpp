#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minDeletion(char* s, int k) {
    int freq[26] = {0};

    for(int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    int arr[26];
    int n = 0;

    for(int i = 0; i < 26; i++)
        if(freq[i] > 0) arr[n++] = freq[i];

    if(n <= k) return 0;

    qsort(arr, n, sizeof(int), cmpInt);

    int deletions = 0;
    for(int i = 0; i < n - k; i++)
        deletions += arr[i];

    return deletions;
}
