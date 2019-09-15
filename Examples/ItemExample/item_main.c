#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/Item/item.h"

void printData(int *input);


int main(void) {

    int vett[] = {1,2,3,4};
    void *data; 

    size_t size = sizeof(vett);

    pItem elem = readItem(&vett, size, "yolo");

    data = getData(elem);

    printData((int *) data);
    
    destroyItem(&elem);

    data = NULL;

    itemCheckVoid(elem);

    elem = readItem(&vett, size, "yolo");
    data = getData(elem);
    destroyItem(&elem);

    printData((int *) data);

    return 0;
}

void printData(int *input){
    int i, value;

    for (i = 0; i<4; i++) {
        value = *(input + i);
        printf("%d\n", value);
    }
}
