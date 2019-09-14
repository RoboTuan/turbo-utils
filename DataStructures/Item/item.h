#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

// First-class ADT for item, 
// the client can only see a pointer to the struct Item.
// The key (a pointer) points at the name of the item

typedef struct item *pItem;
typedef char *pKey;

pItem createItem(size_t dataSize);
void destroyItem(pItem element);

pItem readItem(void *inputData, size_t dataSize, FILE *file);
pKey readKey(FILE *file);

void printItem(pItem element);
void printKey(pKey k);

pKey getKey(pItem element);
int keycmp(pKey k1, pKey k2);

int itemCheckVoid(pItem element);
//pItem itemSetVoid(void);

#endif
