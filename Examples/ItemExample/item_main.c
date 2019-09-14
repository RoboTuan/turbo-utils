#include <stdio.h>
#include <string.h>
#include "../../DataStructures/Item/item.h"


int main(void) {

    int vett[] = {1,2,3,4};

    size_t size = sizeof(vett);

    pItem elem = readItem(&vett, size, stdin);
    
    printf("%p\n", elem);
    
    printItem(elem);
    
    destroyItem(elem);
    
    printItem(elem);

    return 0;
}
