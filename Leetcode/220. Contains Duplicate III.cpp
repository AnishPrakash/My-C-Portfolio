struct Bucket {
    long long key;
    long long val;
    UT_hash_handle hh;
};
struct Bucket *map = NULL;
long long getID(long long x, long long w) {
    if (x < 0) {
        return (x + 1) / w - 1;
    }
    return x / w;
}
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    if (numsSize == 0 || k <= 0 || t < 0) return false;
    map = NULL;
    long long w = (long long)t + 1;
    for (int i = 0; i < numsSize; i++) {
        long long num = nums[i];
        long long bucketID = getID(num, w);
        struct Bucket *el;
        HASH_FIND(hh, map, &bucketID, sizeof(long long), el);
        if (el) {
            struct Bucket *current, *tmp;
            HASH_ITER(hh, map, current, tmp) {
                HASH_DEL(map, current);
                free(current);
            }
            return true;
        }
        long long leftID = bucketID - 1;
        HASH_FIND(hh, map, &leftID, sizeof(long long), el);
        if (el && llabs(el->val - num) <= t) {
            struct Bucket *current, *tmp;
            HASH_ITER(hh, map, current, tmp) {
                HASH_DEL(map, current);
                free(current);
            }
            return true;
        }
        long long rightID = bucketID + 1;
        HASH_FIND(hh, map, &rightID, sizeof(long long), el);
        if (el && llabs(el->val - num) <= t) {
            struct Bucket *current, *tmp;
            HASH_ITER(hh, map, current, tmp) {
                HASH_DEL(map, current);
                free(current);
            }
            return true;
        }
        el = (struct Bucket*)malloc(sizeof(struct Bucket));
        el->key = bucketID;
        el->val = num;
        HASH_ADD(hh, map, key, sizeof(long long), el);
        if (i >= k) {
            long long oldID = getID(nums[i - k], w);
            struct Bucket *toDelete;
            HASH_FIND(hh, map, &oldID, sizeof(long long), toDelete);
            if (toDelete) {
                HASH_DEL(map, toDelete);
                free(toDelete);
            }
        }
    }
    struct Bucket *current, *tmp;
    HASH_ITER(hh, map, current, tmp) {
        HASH_DEL(map, current);
        free(current);
    }
    return false;
}