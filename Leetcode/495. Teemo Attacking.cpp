int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0) return 0;
    
    int totalTime = 0;
    
    for (int i = 0; i < timeSeriesSize - 1; i++) {
        int diff = timeSeries[i + 1] - timeSeries[i];
        if (diff < duration) {
            totalTime += diff;
        } else {
            totalTime += duration;
        }
    }
    
    return totalTime + duration;
}