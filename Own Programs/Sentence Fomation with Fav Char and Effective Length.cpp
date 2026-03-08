#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    int n;
    char a;
    char words[1000];
    char word[20][100]; 
    int k = 0;
    printf("Max char per line: ");
    scanf("%d", &n);
    printf("Favorite Character: ");
    scanf(" %c", &a); 
    getchar(); 
    printf("Words: ");
    fgets(words, sizeof(words), stdin);
    words[strcspn(words, "\n")] = 0;
    char* token = strtok(words, " ,");
    while (token != NULL) {
        strcpy(word[k++], token);
        token = strtok(NULL, " ,");
    }
    int weights[20]; 
    int used[20] = {0};
    for (int i = 0; i < k; i++) {
        int len = strlen(word[i]);
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (tolower(word[i][j]) == tolower(a)) {
                count++;
            }
        }
        weights[i] = len - count;
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (weights[j] < weights[j + 1]) {
                int temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;
                char tempWord[100];
                strcpy(tempWord, word[j]);
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], tempWord);
            }
        }
    }
    printf("\nOutput:\n");
    for (int i = 0; i < k; i++) {
        // If this word is already used in a previous line, skip it
        if (used[i]) continue;
        printf("%s", word[i]);
        int currentLineLen = weights[i];
        used[i] = 1;
        for (int j = i + 1; j < k; j++) {
            if (!used[j] && (currentLineLen + weights[j] <= n)) {
                printf(" %s", word[j]);
                currentLineLen += weights[j];
                used[j] = 1;
            }
        }
        printf(" (%d)\n", currentLineLen);
    }
    return 0;
}