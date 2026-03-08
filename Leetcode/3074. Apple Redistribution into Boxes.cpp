int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int total = 0;
    for(int i = 0; i < appleSize; i++)
        total += apple[i];

    qsort(capacity, capacitySize, sizeof(int), cmpDesc);

    int sum = 0, count = 0;
    for(int i = 0; i < capacitySize; i++) {
        sum += capacity[i];
        count++;
        if(sum >= total) return count;
    }
    return count;
}
