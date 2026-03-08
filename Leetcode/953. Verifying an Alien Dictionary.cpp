bool isAlienSorted(char** words, int wordsSize, char* order) {
    int map[26];
    for (int i = 0; i < 26; i++) {
        map[order[i] - 'a'] = i;
    }
    
    for (int i = 0; i < wordsSize - 1; i++) {
        char* w1 = words[i];
        char* w2 = words[i+1];
        int j = 0;
        
        while (w1[j] && w2[j]) {
            if (w1[j] != w2[j]) {
                if (map[w1[j] - 'a'] > map[w2[j] - 'a']) return false;
                goto next_pair;
            }
            j++;
        }
        
        if (strlen(w1) > strlen(w2)) return false;
        
        next_pair:;
    }
    
    return true;
}