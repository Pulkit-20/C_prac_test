#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    int *buffer;
    int front;
    int rear;
    int size;
    int curr_size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = malloc(sizeof(MyCircularQueue));
    queue->buffer = malloc(sizeof(int) * k);
    queue->size = k;
    queue->front =0;
    queue->rear =-1;
    queue->curr_size =0;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->curr_size <=0;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->curr_size > obj->size-1;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(!myCircularQueueIsFull(obj)){
        obj->rear++;
        obj->rear = obj->rear % (obj->size);
        obj->buffer[obj->rear] = value;
        obj->curr_size++;
        return true;
    }
    return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!myCircularQueueIsEmpty(obj)){
        obj->front++;
        obj->front = obj->front % (obj->size);
        obj->curr_size--;
        return true;
    }
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->buffer[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->buffer[obj->rear];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->buffer);
    free(obj);
}