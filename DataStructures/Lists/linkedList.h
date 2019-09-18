#define TRUE 1
#define FALSE 0

#include "../Item/item.h"

typedef struct linkedList *plinkedList;

plinkedList createList(void);
void destroyList(plinkedList *list);

void insertHead(plinkedList list, pItem element);
void insertTail(plinkedList list, pItem element);

void orderByKey(plinkedList list);
void deleteKey(plinkedList list, pKey k);

int searchKey(plinkedList list, pKey k, pItem **result, int FIRST_OCCURENCY);
int getNumber(plinkedList list);

void printList(plinkedList list);
