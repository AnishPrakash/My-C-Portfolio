char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    for (int i = 0; i < pathsSize; i++) {
        char* candidate = paths[i][1];
        int found = 0;
        
        for (int j = 0; j < pathsSize; j++) {
            if (strcmp(candidate, paths[j][0]) == 0) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            return candidate;
        }
    }
    return "";
}