#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
        return "0";

    int n1 = strlen(num1);
    int n2 = strlen(num2);
    int* res = (int*)calloc(n1 + n2, sizeof(int));

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    char* ans = (char*)malloc(n1 + n2 + 1);
    int k = 0, i = 0;

    while (i < n1 + n2 && res[i] == 0) i++;
    while (i < n1 + n2) ans[k++] = res[i++] + '0';
    ans[k] = '\0';

    free(res);
    return ans;
}
