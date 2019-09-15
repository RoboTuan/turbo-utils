#include <stdio.h>
#include <string.h>
#include "../../DataStructures/Item/item.h"


int main(void) {

    int vett[] = {1,2,3,4};

    size_t size = sizeof(vett);

    pItem elem = readItem(&vett, size, "yolo");
    
    printItem(elem);
    
    destroyItem(&elem);

    itemCheckVoid(elem);
    
    printItem(elem);

    return 0;
}
