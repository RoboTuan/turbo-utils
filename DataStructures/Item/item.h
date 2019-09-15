#ifndef ITEM_H
#define ITEM_H

// First-class ADT for item, 
// the client can only see a pointer to the struct Item.
// The key (a pointer) points at the name of the item
// Using a *void for pItem->data

typedef struct item *pItem;
typedef char *pKey;

// Passing a pointer to pItem (pointer to pointer to the struct item)
// so that itemSetVoid can be used inside destroyItem (see below)_
// It destroys both the item and the data but the client has to 
// put his "void *data" to null after the destruction for better security
void destroyItem(pItem *element);

pItem readItem(void *inputData, size_t dataSize, const char* string);

//void printItem(pItem element);
void printKey(pKey k);
void *getData(pItem element);

pKey getKey(pItem element);
int keycmp(pKey k1, pKey k2);

// Returns 1 is element is void, 0 otherwise
int itemCheckVoid(pItem element);

// Passing a pointer to pItem (pointer to pointer to the struct item)
// to set the element to NULL after it free()
void itemSetVoid(pItem *element);

#endif
