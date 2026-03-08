int minimumDeletions(char* s) {
    int b_count = 0;
    int deletions = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            b_count++;
        } else {
            if (b_count > 0) {
                deletions++;
                b_count--;
            }
        }
    }
    return deletions;
}