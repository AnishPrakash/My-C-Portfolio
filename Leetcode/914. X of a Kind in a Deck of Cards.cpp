int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize) {
    int count[10000] = {0};
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }
    
    int g = -1;
    for (int i = 0; i < 10000; i++) {
        if (count[i] > 0) {
            if (g == -1) g = count[i];
            else g = gcd(g, count[i]);
        }
    }
    
    return g >= 2;
}