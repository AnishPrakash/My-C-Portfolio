int binaryGap(int n) {
    int lastPos = -1;
    int maxDist = 0; 
    for (int i = 0; i < 32; i++) {
        if ((n >> i) & 1) {
            if (lastPos != -1) {
                int dist = i - lastPos;
                if (dist > maxDist) {
                    maxDist = dist;
                }
            }
            lastPos = i;
        }
    }
    return maxDist;
}