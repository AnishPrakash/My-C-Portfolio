int* distributeCandies(int candies, int num_people, int* returnSize) {
    int* res = (int*)calloc(num_people, sizeof(int));
    *returnSize = num_people;
    int i = 0;
    while (candies > 0) {
        int give = i + 1;
        if (candies < give) {
            give = candies;
        }
        res[i % num_people] += give;
        candies -= give;
        i++;
    }
    return res;
}