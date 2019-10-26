#include <stdio.h>
#include <stdlib.h>
#include "vector_queue.h"

int main(){
    int select, elements, num;
    printf("Choose an option:\n\n");
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
            scanf("%d", &elements);
        }

        printf("Insert elements: ");
        for(int i=0; i<elements; i++){
            scanf("%d", &num);
            insert(num);
        }

        //break;

    case 2:
        //remove();
        break;

    case 3:
        //print();
        break;

    case 4:
        //delete();
        break;

    case 5:
        break;
    
    }
    return 0;
}