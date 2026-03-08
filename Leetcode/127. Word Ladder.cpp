#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int idx;
    int dist;
} QNode;

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int n = wordListSize;
    int wordLen = strlen(beginWord);
    int endIndex = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endIndex = i;
            break;
        }
    }

    if (endIndex == -1) return 0;

    bool* visited = (bool*)calloc(n, sizeof(bool));
    QNode* queue = (QNode*)malloc((n + 1) * sizeof(QNode));
    int head = 0, tail = 0;

    // Add beginWord equivalent processing
    // Instead of adding beginWord to list, we check neighbors of beginWord first
    
    // Check direct connections from beginWord
    for (int i = 0; i < n; i++) {
        int diff = 0;
        for (int k = 0; k < wordLen; k++) {
            if (beginWord[k] != wordList[i][k]) {
                diff++;
                if (diff > 1) break;
            }
        }
        if (diff == 1) {
            queue[tail].idx = i;
            queue[tail].dist = 2;
            visited[i] = true;
            tail++;
        }
    }

    while (head < tail) {
        QNode curr = queue[head++];
        int u = curr.idx;
        int d = curr.dist;

        if (u == endIndex) {
            free(visited);
            free(queue);
            return d;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int diff = 0;
                for (int k = 0; k < wordLen; k++) {
                    if (wordList[u][k] != wordList[i][k]) {
                        diff++;
                        if (diff > 1) break;
                    }
                }
                if (diff == 1) {
                    visited[i] = true;
                    queue[tail].idx = i;
                    queue[tail].dist = d + 1;
                    tail++;
                }
            }
        }
    }

    free(visited);
    free(queue);
    return 0;
}