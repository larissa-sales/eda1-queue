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

int size_num(int num){
    int size=0;

    while(num!=0){
        size++;
        num = num/10;
    }
    return size;
}

void print(){
    int i=0, count=0, aux;

    for(aux=0; aux<size(); aux++){
        count += size_num(queue[aux]);
    }

    printf(" ");

    for(i = 0; i < size()*3+count; i++){
        printf("-");
    }

    if(!is_empty()){
        printf("\n|");
    }

    for(i = 0; i < N; i++){
        if(queue[i] == 0){
            if(i==N-1){ //last position
                printf(" ");
            }
            else if (i==0){ //first position
                printf("| ");
            }
            
        }
        else{
            printf("  %d  |", queue[i]);
        }
    }

    printf("\n ");

    for(i = 0; i < size()*3+count-1; i++){
        printf("-");
    }
    
    printf("\n");
    
    if(p == 0 && u == 0){
        printf("p  u\n");
    }
    else{
        for(i = 0; i < N; i++){
            if(queue[i] != 0){
                printf(" p ");
                break;
            }
            else{
                printf("    ");
            }
        }
        for(i = 0; i < N; i++){
            if(queue[i] != 0 && queue[i+1] == 0){
                printf("  u  \n");
                break;
            }
                else{
                printf("     ");
            }
        }
    }
}