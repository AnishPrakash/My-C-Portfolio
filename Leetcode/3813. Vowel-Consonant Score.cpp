int vowelConsonantScore(char* s) {
    int v=0,c=0;
    for(int i = 0; s[i]!='\0'; i++){
        char ch = tolower(s[i]);
        if (ch>='a' && ch<='z'){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i] == 'o' || s[i] == 'u'){
                v++;
            }
            else{
                c++;
            }
            
        }
    }
    if (c==0) return 0;
    return (v/c);
}