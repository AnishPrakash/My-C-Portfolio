bool checkRecord(char* s) {
    int absents = 0;
    int lates = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absents++;
            if (absents >= 2) return false;
            lates = 0;
        } else if (s[i] == 'L') {
            lates++;
            if (lates >= 3) return false;
        } else {
            lates = 0;
        }
    }
    return true;
}