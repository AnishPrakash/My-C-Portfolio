#define MAX_VAL 100002
#define MOD 1000000007

int bit[MAX_VAL];

void update(int idx) {
    for (; idx < MAX_VAL; idx += idx & -idx)
        bit[idx]++;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

int createSortedArray(int* instructions, int instructionsSize) {
    memset(bit, 0, sizeof(bit));
    long long cost = 0;
    
    for (int i = 0; i < instructionsSize; i++) {
        int x = instructions[i];
        int less = query(x - 1);
        int greater = i - query(x);
        
        cost = (cost + (less < greater ? less : greater)) % MOD;
        update(x);
    }
    
    return (int)cost;
}