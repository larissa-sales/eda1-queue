#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

static int *queue;
static int p, u, N;

void create(){
    N=5;
    queue = malloc(N*sizeof(int));
    p=0;
    u=0;
}

int insert_element(int x){
    int aux=1;
    if(is_full()){
        aux=resize();
    }
    if(aux){
        queue[u++]=x;
        if(u==N){
            u=0;
        }
    }
    return aux;
}

int remove_element(int *x){
    if(!is_empty()){
        *x-queue[p++];
        if(p==N){
            p=0;
        }
        return 1;
    }
    return 0;
}

int is_full(){
    return (u+1)%N==p;
}

int is_empty(){
    return p==u;
}

int resize(){
    int i, j;

    queue = realloc(queue, 2 * N * sizeof(int));

    if(queue == NULL){
        return 0;
    }

    if(u != N - 1){
        if(u-1 < N - p){
            for(i = N, j = 0; j < u; i++, j++){
                queue[i] = queue[j];
            }
            u = N + u;
        }
        else{
            for(i = p, j = N + p; i < N; i++, j++){
                queue[j] = queue[i];
            }
            p = N + p;
        }
    }
    N *= 2;
    return 1;
}

void clear_queue(){
    free(queue);
}

int size(){
    int sum=u-p;

    if(p>u){
        sum=N+sum;
    }
    return sum;
}

void print(){

}