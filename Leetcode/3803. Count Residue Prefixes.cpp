int residuePrefixes(char* s){
    int seen[26] = {0};
    int count1 = 0, count2 = 0;
    for (int i = 0; s[i]!='\0'; i++){
        if(seen[s[i]-'a'] == 0){
            seen[s[i]-'a'] = 1;
            count2++;
        }
        if(count2 == (i+1)%3){
            count1++;
        }
    }
    return count1;
}