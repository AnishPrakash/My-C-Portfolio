bool hasAllCodes(char * s, int k) {
    int n = strlen(s);
    int total_needed = 1 << k;
    if (n - k + 1 < total_needed) {
        return false;
    }
    bool *found = (bool *)calloc(total_needed, sizeof(bool));
    int current_hash = 0;
    int mask = total_needed - 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        current_hash = ((current_hash << 1) & mask) | (s[i] - '0');
        if (i >= k - 1) {
            if (!found[current_hash]) {
                found[current_hash] = true;
                count++;
            }
        }
    }
    free(found);
    return count == total_needed;
}