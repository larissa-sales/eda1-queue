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

int insert_element(int x){
    if(!is_full(q)){
        q->queue[q->u] = x;
        q->u++;
        return 1;
    }
    return 0;
}

int remove_element(int *value){
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

void clear_queue(){
    free(q);
}

int size(){
    return q->u - q->p;
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
    int i, aux, count=0, num;

    for(aux=0; aux<q->u; aux++){
        count += size_num(q->queue[aux]);
    }

    printf(" ");

    for(i = 0; i < (q->u)*3+count-1; i++){
        printf("-");
    }

    if(!is_empty()){
        printf("\n|");
    }
        
    for(i = 0; i < q->u; i++){
        printf(" %d |", q->queue[i]);
    }

    printf("\n ");

    for(i = 0; i < (q->u)*3+count-1; i++){
        printf("-");
    }
    
    printf("\n");

    if(q->p == 0){
        count = size_num(q->queue[q->p]);
        if(count==1) {
            printf("  p");
        }
        else if(count==2){
            printf("  p ");
        }
        else{
            printf("   p ");
        }

        for(i=1; i<(q->u); i++){
            printf("   ");

            if(i != q->u-1){
                num = q->queue[i];
                count= size_num(num);
                printf(" ");
            }
        }

        count = size_num(q->queue[q->u-1]);

        if (count <= 2){
            printf("u");
        }
        else if(count == 3){
            printf(" u");
        }  
        
    }
    else{
        for(i = 0; i<q->u; i++){
            count = size_num(q->queue[i]);

            printf("  ");

            if(i == q->p){
                if (count <=2){
                    printf("p");
                }
                else{
                    printf(" p");
                }
            }

            if(q->queue[q->u-1] == q->queue[i]){
                if (count <=2){
                    printf("u");
                }
                else{
                    printf(" u");
                }
                break;
            }
            
            if(!(i== q->p && count == 1)){ 
                for(aux = 0; aux < count; aux++){
                    if(q->queue[i] == q->queue[q->p] && count == 2){
                        count -= 1;
                    }
                    if(q->queue[i] == q->queue[q->p] && count == 3){
                        count -= 2;
                    }
                    
                    printf(" ");
                }
            }
            printf(" ");
        }    
    }
}