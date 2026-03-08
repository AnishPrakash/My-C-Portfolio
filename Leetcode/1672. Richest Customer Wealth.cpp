int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max_wealth = 0;
    for (int i = 0; i < accountsSize; i++) {
        int current_wealth = 0;
        for (int j = 0; j < accountsColSize[i]; j++) {
            current_wealth += accounts[i][j];
        }
        if (current_wealth > max_wealth) {
            max_wealth = current_wealth;
        }
    }
    return max_wealth;
}