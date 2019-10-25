#include <stdio.h>
#include <stdlib.h>
#include "vector_queue.h"
#define N 5

typedef struct queue{
    int queue[N], p, u;
} queue;

queue *q;

void create(){
    q = malloc(sizeof(queue));
    q->p=0;
    q->u=0;
}

int insert(int x){
    if(!is_full(q)){
        q->queue[q->u] = x;
        q->u++;
        return 1;
    }
    return 0;
}

int remove(int *value){
    if(!is_empty(q)){
        *value = q->queue[q->p];
        q->p++;
        return 1;
    }
    return 0;
}

int is_full(){
    return q->u == N;
}

int is_empty(){
    if(q->p == q->u){
        q->u = 0;
        q->p = 0;
        return 1;
    }
    return 0;
}

int size(){
    return q->u - q->p;
}