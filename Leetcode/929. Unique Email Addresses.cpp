int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}
int numUniqueEmails(char** emails, int emailsSize) {
    char** normalized = (char**)malloc(emailsSize * sizeof(char*));
    for (int i = 0; i < emailsSize; i++) {
        normalized[i] = (char*)calloc(105, sizeof(char));
        int j = 0, k = 0;
        int ignore = 0;
        int domain = 0;
        while (emails[i][j] != '\0') {
            if (emails[i][j] == '@') {
                domain = 1;
                normalized[i][k++] = emails[i][j++];
            } else if (domain) {
                normalized[i][k++] = emails[i][j++];
            } else {
                if (emails[i][j] == '+') {
                    ignore = 1;
                    j++;
                } else if (emails[i][j] == '.') {
                    j++;
                } else if (!ignore) {
                    normalized[i][k++] = emails[i][j++];
                } else {
                    j++;
                }
            }
        }
    }
    qsort(normalized, emailsSize, sizeof(char*), compareStrings);
    int count = 0;
    if (emailsSize > 0) count = 1;
    for (int i = 1; i < emailsSize; i++) {
        if (strcmp(normalized[i], normalized[i - 1]) != 0) {
            count++;
        }
    }
    for (int i = 0; i < emailsSize; i++) {
        free(normalized[i]);
    }
    free(normalized);
    return count;
}