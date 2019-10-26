#include <stdio.h>
#include <stdlib.h>
#include "circular_queue_linked_list.h"

typedef struct cell{
    int data;
    struct cell *next;
} cell;

cell *queue;

void create(){
    queue = malloc(sizeof(cell));
    queue->next = queue;
}

int insert_element(int x){
    cell *new;
    new = malloc(sizeof(cell));

    if(is_full(new)){
        return 0;
    }
    new->next = queue->next;
    queue->next = new;
    queue->data = x;
    queue = new;
    return 1;
}

int remove_element(int *value){
    if(is_empty()){
        return 0;
    }
    cell *nothing = queue->next;
    *value = nothing->data;
    queue->next = nothing->next;
    free(nothing);
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

int size(){
    if(queue->next == NULL){
        return 0;
    }
    int sum=0;

    cell *count = queue;

    while(count->next != queue){
        sum++;
        count = count->next;
    }
    return sum;
}

void print();