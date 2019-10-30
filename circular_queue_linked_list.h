#ifndef _CIRCULAR_QUEUE_LINKED_LIST_H
#define _CIRCULAR_QUEUE_LINKED_LIST_H

void create();

int insert_element(int x);

int remove_element(int *value);

int is_full();

int is_empty();

void clear_queue();

int size();

void print();

#endif