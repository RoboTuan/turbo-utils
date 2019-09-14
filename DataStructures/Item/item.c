#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "item.h"

#define MAX_NAME 30

struct item{
    char name[MAX_NAME];
    void *data;
};


// Reading and initializing a new pointer to item (new_item)
pItem readItem(void *inputData, size_t dataSize, FILE *file){
    int offset;
    pItem new_item = createItem(dataSize);

    // reading each byte of the data pointed by "void *data"
    // though a for cicle, using uint8_t which is a 8-bit (1 byte) type
    for(offset = 0; offset < dataSize; offset++){
        *((uint8_t *)(new_item->data + offset)) = *((uint8_t *)(inputData + offset));
    }
    
    if (file == stdin){
        printf("Insert element's name\n");
    }
    
    fscanf(file, "%s", new_item->name);
    return new_item;
}


pItem createItem(size_t dataSize){
    pItem new_item = malloc(sizeof(*new_item));
    if (new_item == NULL){
       fprintf(stderr,"%s\n","Failure at creating a new Item, could not allocate memory");
       exit(EXIT_FAILURE);
    }

    new_item->name[0] = '\0';
    new_item->data = malloc(dataSize);
    if (new_item->data == NULL){
       fprintf(stderr,"%s\n","Failure at creating new generic data, could not allocate memory");
       exit(EXIT_FAILURE);
    }

    return new_item;
}


void destroyItem(pItem element){
    if (element->data != NULL){
        free(element->data);
    }

    if (element->name[0] != '\0'){
        // resetting element->name
        memset(element->name,0,sizeof(element->name));
    }
    free(element);
}


void printItem(pItem element){
    int i;
    int *value;
    printf("%s\n",element->name);
    

    // make better arithmetic for void pointer
    // fo example: ((int *) (element->data)) + i
    for (i = 0; i<4; i++) {
        value = (int *)((element->data) + i * sizeof(int));
        printf("%d\n",*value);
    }
}