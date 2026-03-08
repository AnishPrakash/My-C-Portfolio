char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char* ans;
    ans = (char*)malloc((wordsSize+1)*sizeof(char));
    for(int i = 0; i<wordsSize; i++){
        int l = strlen(words[i]);
        int sum = 0;
        for(int j = 0; j<l; j++){ 
            sum += weights[words[i][j]-'a'];
        }
        int r = sum%26;
        int t = 25-r;
        ans[i] = t + 'a';
    }
    ans[wordsSize] = '\0';
    return ans;
}