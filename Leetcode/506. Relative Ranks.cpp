#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int score;
    int index;
} Player;

int comparePlayers(const void* a, const void* b) {
    return ((Player*)b)->score - ((Player*)a)->score; // Descending order
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    Player* players = (Player*)malloc(scoreSize * sizeof(Player));
    for (int i = 0; i < scoreSize; i++) {
        players[i].score = score[i];
        players[i].index = i;
    }
    
    qsort(players, scoreSize, sizeof(Player), comparePlayers);
    
    char** result = (char**)malloc(scoreSize * sizeof(char*));
    *returnSize = scoreSize;
    
    for (int i = 0; i < scoreSize; i++) {
        // Allocate enough space for rank string (digits + null terminator)
        result[players[i].index] = (char*)malloc(15 * sizeof(char));
        
        if (i == 0) {
            strcpy(result[players[i].index], "Gold Medal");
        } else if (i == 1) {
            strcpy(result[players[i].index], "Silver Medal");
        } else if (i == 2) {
            strcpy(result[players[i].index], "Bronze Medal");
        } else {
            sprintf(result[players[i].index], "%d", i + 1);
        }
    }
    
    free(players);
    return result;
}