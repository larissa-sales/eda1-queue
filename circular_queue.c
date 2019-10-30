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

