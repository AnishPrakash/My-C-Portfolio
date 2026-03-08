#define MAX(a, b) ((a) > (b) ? (a) : (b))
bool canJump(int* nums, int numsSize) {
    int farthest = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > farthest) {
            return false;
        }
        farthest = MAX(farthest, i + nums[i]);
        if (farthest >= numsSize - 1) {
            return true;
        }
    }
    return true;
}
