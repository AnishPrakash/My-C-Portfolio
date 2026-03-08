bool rotateString(char* s, char* goal) {
    int lenS = strlen(s);
    int lenGoal = strlen(goal);
    if (lenS != lenGoal) {
        return false;
    }
    char* doubleS = (char*)malloc((2 * lenS + 1) * sizeof(char));
    strcpy(doubleS, s);
    strcat(doubleS, s);
    bool result = (strstr(doubleS, goal) != NULL);
    free(doubleS);
    return result;
}