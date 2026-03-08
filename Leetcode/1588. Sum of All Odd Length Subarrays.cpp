int sumOddLengthSubarrays(int* arr, int arrSize) {
    int totalSum = 0;  
    for (int i = 0; i < arrSize; i++) {
        int totalOccurrences = (i + 1) * (arrSize - i);
        int oddOccurrences = (totalOccurrences + 1) / 2;
        totalSum += oddOccurrences * arr[i];
    }
    return totalSum;
}