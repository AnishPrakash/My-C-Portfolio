char* reverseByType(char* s){
    int l = strlen(s);
    char temp1[l],temp2[l];
    int c1 = 0, c2 = 0;
    for(int i = 0; i<l; i++){
        if(isalpha(s[i])){
            temp1[c1] = s[i];
            c1++;
        }
        if(!isalpha(s[i])){
            temp2[c2] = s[i];
            c2++;
        }
    }
    for(int i = 0; i<l; i++){
        if(isalpha(s[i])){
            s[i] = temp1[c1-1];
            c1--;
        }
        if(!isalpha(s[i])){
            s[i] = temp2[c2-1];
            c2--;
        }
    }
    return s;
}