/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++){
        int num = i + 1;
        result[i] = (char*)malloc(9 * sizeof(char));
        if (num % 3 == 0 && num % 5 == 0) {
            sprintf(result[i], "FizzBuzz");
        }
        else if (num % 3 == 0) {
            sprintf(result[i], "Fizz");
        }
        else if (num % 5 == 0) {
            sprintf(result[i], "Buzz");
        }
        else {
            sprintf(result[i], "%d", num);
        }
    }
    *returnSize = n;
    return result;
}