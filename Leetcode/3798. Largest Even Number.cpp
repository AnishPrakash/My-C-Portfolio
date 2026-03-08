char* largestEven(char* s) {
    int k = strlen(s);
    for (int i = k-1; i>=0; i--){
        if (s[i] == '2'){
            s[i+1] = '\0';
            return s;
        }
    }
    s[0] = '\0';
    return s;
}