#include <stdio.h>
int main(){
	int T;
    scanf("%d", &T);
    int I = 0;
    while (I < T) {
        int r, c;
        scanf("%d %d", &r, &c);
        int arr[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int r1, c1;
        scanf("%d %d", &r1, &c1);
        for (int i = 0; i < r; i++) {
            if (i == r1) {
                continue;
            }
            for (int j = 0; j < c; j++) {
                if (j == c1) {
                    continue;
                }
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        I++;
    }
    return 0;
}