int countBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int cmp(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    int bitsA = countBits(valA);
    int bitsB = countBits(valB);
    
    if (bitsA != bitsB) {
        return bitsA - bitsB;
    }
    return valA - valB;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}