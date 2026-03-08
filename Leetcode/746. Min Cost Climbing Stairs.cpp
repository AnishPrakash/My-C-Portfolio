int minCostClimbingStairs(int* cost, int costSize) {
    int prev2 = 0, prev1 = 0;
    
    for (int i = 0; i < costSize; i++) {
        int cur = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    
    return prev1 < prev2 ? prev1 : prev2;
}
