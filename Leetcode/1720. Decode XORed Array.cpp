int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    *returnSize = encodedSize + 1;
    int* decoded = (int*)malloc((*returnSize) * sizeof(int));
    
    decoded[0] = first;
    for (int i = 0; i < encodedSize; i++) {
        decoded[i + 1] = decoded[i] ^ encoded[i];
    }
    
    return decoded;
}