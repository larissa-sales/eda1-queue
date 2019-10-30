#include <stdio.h>
#include <stdlib.h>
#include "circular_queue_linked_list.h"

int main(){
    int select=0, elements, num;
    create();

    while(select!=5){
        printf("\n\n >>> Choose an option:\n\n");
        printf("1. Insert elements on queue.\n");
        printf("2. Remove elements from queue.\n");
        printf("3. Print queue.\n");
        printf("4. Restart queue.\n");
        printf("5. Exit.\n\n");

        scanf("%d", &select);

        switch (select){
            case 1:
                printf("How many elements do you want to insert? ");
                scanf("%d", &elements);
                printf("\n");

                if(elements<0 || elements>999){
                    printf("It needs to be from 0 to 999!");
                    scanf("%d", &elements);
                }

                for(int i=0; i<elements; i++){
                    printf("Insert element %d: ", i+1);
                    scanf("%d", &num);

                    while(num<0 || num>999){                                        
                        printf("It needs to be from 0 to 999!");
                        printf(" Insert element %d again: ", i+1);
                        scanf("%d", &num);
                    }

                    insert_element(num);

                    if(insert_element(num)){
                        printf("Done!\n");
                    }
                }

                break;

            case 2:
                printf("How many elements do you want to remove? ");
                scanf("%d", &elements);
                printf("\n");

                if(is_empty()){
                    printf("The queue is empty!\n");
                }
                else{
                    for(int i = 0; i < elements; i++){
                        if(is_empty()){
                            printf("Cant remove more, the queue is empty!\n");
                            break;
                        }
                        else{
                            remove_element(&num);
                            printf("Number removed: %d\n", num);
                        }
                    }
                }

            case 3:
                print();
                break;

            case 4:
                clear_queue();
                break;
            
            }
    } 

    return 0;
}