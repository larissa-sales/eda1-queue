#ifndef _CIRCULAR_QUEUE_H
#define _CIRCULAR_QUEUE_H

void create();

int insert_element(int x);

int remove_element(int *value);

int is_full();

int is_empty();

int size();

void print();

#endif