typedef struct {
    int *queue;
    int front;
    int rear;
    int size; 
    int capacity;
} MyStack;

MyStack* myStackCreate(){
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->capacity = 100;
    obj->queue = (int*)malloc(sizeof(int)*obj->capacity);
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue[obj->rear++] = x;
    obj->size++;
    for(int i = 0; i<obj->size-1; i++){
        obj->queue[obj->rear++] = obj->queue[obj->front++];
    }   
}

int myStackPop(MyStack* obj) {
    obj->size--;
    return obj->queue[obj->front++];
}

int myStackTop(MyStack* obj) {
    return obj->queue[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0 ;   
}

void myStackFree(MyStack* obj) {
    free(obj->queue);
    free(obj);
}
