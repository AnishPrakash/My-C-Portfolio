bool canConstruct(char* ransomNote, char* magazine) {
    int inventory[26] = {0};
    for (int i = 0; magazine[i] != '\0'; i++) {
        inventory[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int charIndex = ransomNote[i] - 'a';
        if (inventory[charIndex] == 0) {
            return false; 
        }
        inventory[charIndex]--;
    }
    return true;
}