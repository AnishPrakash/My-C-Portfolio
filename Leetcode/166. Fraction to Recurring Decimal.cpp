#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long _abs(long long a) {
    return a < 0 ? -a : a;
}

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    char* result = (char*)malloc(10000);
    int pos = 0;

    if ((numerator < 0) ^ (denominator < 0)) {
        result[pos++] = '-';
    }

    long long n = _abs((long long)numerator);
    long long d = _abs((long long)denominator);

    pos += sprintf(result + pos, "%lld", n / d);
    long long remainder = n % d;

    if (remainder == 0) {
        return result;
    }

    result[pos++] = '.';

    long long* map_rem = (long long*)malloc(10000 * sizeof(long long));
    int* map_pos = (int*)malloc(10000 * sizeof(int));
    int map_size = 0;

    while (remainder != 0) {
        for (int i = 0; i < map_size; i++) {
            if (map_rem[i] == remainder) {
                int insert_pos = map_pos[i];
                memmove(result + insert_pos + 1, result + insert_pos, pos - insert_pos);
                result[insert_pos] = '(';
                pos++;
                result[pos++] = ')';
                result[pos] = '\0';
                free(map_rem);
                free(map_pos);
                return result;
            }
        }

        map_rem[map_size] = remainder;
        map_pos[map_size++] = pos;

        remainder *= 10;
        result[pos++] = (remainder / d) + '0';
        remainder %= d;
        result[pos] = '\0';
    }

    free(map_rem);
    free(map_pos);
    return result;
}