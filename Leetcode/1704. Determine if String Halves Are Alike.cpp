bool halvesAreAlike(char* s) {
    int l = strlen(s);
    int l1 = l/2, l2 = l - l1;
    char* temp1 = (char*)malloc(l1*sizeof(char));
    char* temp2 = (char*)malloc(l2*sizeof(char));
    for (int i = 0; i<l1; i++){
        temp1[i] = tolower(s[i]);
    }
    for (int i = 0; i<l2; i++){
        temp2[i] = tolower(s[l1+i]);
    }
    int vowel1 = 0, vowel2 = 0;
    for (int i = 0; i<l1; i++){
        if (temp1[i] == 'a'|| temp1[i] == 'e' || temp1[i] == 'i' || temp1[i] == 'o' || temp1[i] == 'u'){
            vowel1++;
        }
    }
    for (int i = 0; i<l2; i++){
        if (temp2[i] == 'a'|| temp2[i] == 'e' || temp2[i] == 'i' || temp2[i] == 'o' || temp2[i] == 'u'){
            vowel2++;
        }
    }
    if (vowel1 == vowel2)
        return true;
    else
        return false;


}