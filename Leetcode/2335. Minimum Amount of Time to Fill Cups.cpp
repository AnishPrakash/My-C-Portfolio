int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int fillCups(int* amount, int amountSize) {
    int max = 0, sum = 0;
    for(int i = 0; i < amountSize; i++) {
        if(amount[i] > max) max = amount[i];
        sum += amount[i];
    }
    return (max > sum - max) ? max : (sum + 1) / 2;
}