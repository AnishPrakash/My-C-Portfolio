bool isNumber(char* s) {
    int i = 0;
    while(s[i] == ' ') i++;

    if(s[i] == '+' || s[i] == '-') i++;

    bool num = false, dot = false, exp = false;

    for(; s[i]; i++) {
        if(isdigit(s[i])) {
            num = true;
        }
        else if(s[i] == '.') {
            if(dot || exp) return false;
            dot = true;
        }
        else if(s[i] == 'e' || s[i] == 'E') {
            if(exp || !num) return false;
            exp = true;
            num = false;
            if(s[i+1] == '+' || s[i+1] == '-') i++;
        }
        else if(s[i] == ' ') {
            while(s[i] == ' ') i++;
            return s[i] == '\0' && num;
        }
        else return false;
    }

    return num;
}
