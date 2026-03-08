struct HashTable {
    int key;        
    int id;           
    UT_hash_handle hh; 
};
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct HashTable *users = NULL, *item = NULL;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(users, &nums[i], item);
        if (item) {
            if (abs(i - item->id) <= k) {
                struct HashTable *current, *tmp;
                HASH_ITER(hh, users, current, tmp) {
                    HASH_DEL(users, current);
                    free(current);
                }
                return true;
            }
            item->id = i;
        } 
        else {
            item = malloc(sizeof(struct HashTable));
            item->key = nums[i];
            item->id = i;
            HASH_ADD_INT(users, key, item);
        }
    }
    struct HashTable *current, *tmp;
    HASH_ITER(hh, users, current, tmp) {
        HASH_DEL(users, current);
        free(current);
    }
    return false;
}