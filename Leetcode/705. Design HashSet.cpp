typedef struct {
    bool* map;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    obj->map = (bool*)calloc(1000001, sizeof(bool));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->map[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->map[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->map[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->map);
    free(obj);
}