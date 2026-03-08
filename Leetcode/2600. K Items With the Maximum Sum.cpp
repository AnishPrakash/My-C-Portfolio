int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int sum = 0;

    int take = (k < numOnes) ? k : numOnes;
    sum += take;
    k -= take;

    take = (k < numZeros) ? k : numZeros;
    k -= take;

    take = (k < numNegOnes) ? k : numNegOnes;
    sum -= take;

    return sum;
}
