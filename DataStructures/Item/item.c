// To-do:
// implement better printItem



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "item.h"

// MAX_NAME is the max length for the name (string) of the item
// 30 + 1 for the terminator character '\0'
#define MAX_NAME 30 + 1

struct item{
    char name[MAX_NAME];
    void *data;
};


// Reading and initializing a new pointer to item (new_item)
pItem readItem(void *inputData, size_t dataSize, const char* string){
    int offset;
    //size_t size = sizeof(inputData);
    pItem new_item = createItem(dataSize);

    if (strlen(string) > MAX_NAME)
    {   
        fprintf(stderr, "%s\n", "Length of string exceed 30 characters!");
        exit(EXIT_FAILURE);
    }
    strcpy(new_item->name, string);

    if (itemCheckVoid(new_item)){
        exit(EXIT_FAILURE);
    }

    // Reading each byte of the data pointed by "void *data"
    // though a for cicle, using uint8_t which is a 8-bit (1 byte) type
    // Casting void pointer "new_item->data" to uint8_t for pointer arithmetics
    for(offset = 0; offset < dataSize; offset++){
        *(((uint8_t *) new_item->data) + offset) = *((uint8_t *)(inputData + offset));
    }
    
    return new_item;
}


pItem createItem(size_t dataSize){
    pItem new_item = (pItem) malloc(sizeof(*new_item));

    new_item->name[0] = '\0';
    new_item->data = malloc(dataSize);
    if (new_item->data == NULL){
       fprintf(stderr,"%s\n","Failure at creating new generic data, could not allocate memory");
       exit(EXIT_FAILURE);
    }

    return new_item;
}

// Passing a pointer to pItem (pointer to pointer to the struct item)
// and (*element)->data is equal to a pITem->data
void destroyItem(pItem *element){
    if ((*element)->data != NULL){
        free((*element)->data);
        (*element)->data = NULL;
    }

    if ((*element)->name[0] != '\0'){
        // resetting element->name
        memset((*element)->name,0,sizeof((*element)->name));
    }
    free((*element));
    // Passing a pointer to pItem (pointer to pointer to the struct item)
    itemSetVoid(element);
}

int itemCheckVoid(pItem element){
    if (element == NULL){
       fprintf(stderr,"%s\n","The Item is NULL");
       return 1;
    }
    else{
        fprintf(stdout,"%s %s %s\n","The item", element->name,"is not NULL");
        return 0;
    }
}

void itemSetVoid(pItem *element){
    *element = NULL;
}


void printItem(pItem element){
    int i;
    int *value;
    printKey(element->name);
    
    for (i = 0; i<4; i++) {
        value = ((int *)(element->data)) + i;
        printf("%d\n",*value);
    }
}

pKey getKey(pItem element){
    return element->name;
}

void printKey(pKey k){
    printf("%s\n",k);
}

int keycmp(pKey k1, pKey k2){
    return strcmp(k1,k2);
}

void *getData(pItem element){
    return element->data;
}
