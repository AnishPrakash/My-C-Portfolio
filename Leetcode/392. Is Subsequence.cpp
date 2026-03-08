bool isSubsequence(char* s, char* t) {
    int l = strlen(s);
    int k = strlen(t);
    int j = 0; 
    if (l > k) return false; 
    if (l == 0) return true;
    for (int i = 0; i < k; i++) {
        if (s[j] == t[i]) {
            j++;
        }
        if (j == l) {
            return true;
        }
    }
    return false;
}