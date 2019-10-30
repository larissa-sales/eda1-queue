#include <stdio.h>
#include <stdlib.h>
#include "circular_queue_linked_list.h"

static int sum;

typedef struct cell{
    int data;
    struct cell *next;
} cell;

cell *queue;

void create(){
    queue = malloc(sizeof(cell));
    queue->data = 0;
    queue->next = queue;
    sum = 0;
}

int insert_element(int x){
    cell *new = malloc(sizeof(cell));

    if(new == NULL){
        return 0;
    }

    new->next = queue->next;
    queue->next = new;
    queue->data = x;
    queue = new;
    sum++;
    return 1;
}

int remove_element(int *value){
    if(is_empty()){
        return 0;
    }
    cell *aux = queue->next;
    *value = aux->data;
    queue->next = aux->next;
    free(aux);
    sum--;
    return 1;
}

int is_full(cell *c){
    if(c!=NULL){
        return 1;        
    } 
    else{
        return 0;
    }
}

int is_empty(){
    if(queue->next==queue){
        return 1;
    }
    else{
        return 0;
    }
}

void clear_queue(){
    if(!is_empty()){
        cell *aux, *next;
        next = queue->next;
        
        while(next != queue){
            aux = next;
            next = aux->next;
            free(aux);
        }
    }
}

int size(){
    return sum;
}

void print(){
    cell *aux = queue;

    for(int i=0; i<size(); i++){
        printf("----");
    }

    printf("\n");

    //printf("----------------------");

    for(aux; aux->next != queue; aux = aux->next){
        if(aux->data == 0){
            printf("|");
        }
        else{
            printf("  %d  |", aux->data);
        }
    }

    printf("\n");

    for(int i=0; i<size(); i++){
        printf("----");
    }

    if(sum == 0){
        printf("\np  u\n");
    }
    else{
        for(aux; aux->next != queue; aux = aux->next){
            if(aux->data != 0){
                printf(" p ");
                break;
            }
            else{
                printf("    ");
            }
        }
        for(aux; aux->next != queue; aux = aux->next){
            if(aux->data != 0 && aux->next->data == 0){
                printf("  u  \n");
                break;
            }
                else{
                printf("     ");
            }
        }
    }
}