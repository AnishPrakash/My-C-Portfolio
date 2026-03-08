char* reversePrefix(char* s, int k) {
    for (int i = 0; i<k; i++){
        for (int j = i+1; j<k; j++){
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    return s;
}