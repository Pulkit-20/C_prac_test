#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int arr[100];
    int head;
    int tail;
    int cnt;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj -> head =0;
    obj -> tail =0;
    obj->cnt =0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj == NULL) return;

    obj->cnt++;
    obj->arr[obj->tail] = x;
    obj->tail = (obj->tail +1)%100;
}

int myQueuePop(MyQueue* obj) {
    if(obj == NULL) return NULL;

    obj->cnt--;
    obj->head = (obj->head +1)%100;
    return (obj->arr[(obj->head-1)%100]);
}

int myQueuePeek(MyQueue* obj) {
    if(obj == NULL) return NULL;

    return obj->arr[obj->head];
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj == NULL) return false;
    return (obj->cnt?false:true);
    
}

void myQueueFree(MyQueue* obj) {
    if(obj == NULL) return;
    free(obj);
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/