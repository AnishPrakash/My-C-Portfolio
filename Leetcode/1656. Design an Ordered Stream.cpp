typedef struct {
    char** stream;
    int ptr;
    int size;
} OrderedStream;

OrderedStream* orderedStreamCreate(int n) {
    OrderedStream* obj = (OrderedStream*)malloc(sizeof(OrderedStream));
    obj->stream = (char**)calloc(n + 1, sizeof(char*));
    obj->ptr = 1;
    obj->size = n;
    return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* returnSize) {
    obj->stream[idKey] = value;
    int start = obj->ptr;
    while (obj->ptr <= obj->size && obj->stream[obj->ptr] != NULL) {
        obj->ptr++;
    }
    *returnSize = obj->ptr - start;
    char** result = (char**)malloc((*returnSize) * sizeof(char*));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = obj->stream[start + i];
    }
    return result;
}

void orderedStreamFree(OrderedStream* obj) {
    free(obj->stream);
    free(obj);
}