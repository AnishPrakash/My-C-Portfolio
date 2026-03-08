int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination) {
    int clockwise = 0;
    int total = 0;
    
    if (start > destination) {
        int temp = start;
        start = destination;
        destination = temp;
    }
    
    for (int i = 0; i < distanceSize; i++) {
        total += distance[i];
        if (i >= start && i < destination) {
            clockwise += distance[i];
        }
    }
    
    int counterClockwise = total - clockwise;
    return (clockwise < counterClockwise) ? clockwise : counterClockwise;
}