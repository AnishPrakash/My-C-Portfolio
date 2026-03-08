bool checkDistances(char* s, int* distance, int distanceSize) {
    int firstOccurrence[26];
    for (int i = 0; i < 26; i++) {
        firstOccurrence[i] = -1;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        int charIdx = s[i] - 'a';
        if (firstOccurrence[charIdx] == -1) {
            firstOccurrence[charIdx] = i;
        } 
        else {
            int currentDist = i - firstOccurrence[charIdx] - 1;
            if (currentDist != distance[charIdx]) {
                return false;
            }
        }
    }
    return true;
}