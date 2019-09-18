#include <stdio.h>
#include <stdlib.h>
#include "../../DataStructures/Lists/linkedList.h"

int main(void){

    int vett1[] = {1,2,3};
    int vett2[] = {4,5,6};
    int vett3[] = {7,8,9};
    int vett4[] = {10,11,12};
    int vett5[] = {13,14,15};
    int vett6[] = {16,17,18};



    pItem elem1 = readItem(vett1, sizeof(vett1), "first_item");
    pItem elem2 = readItem(vett2, sizeof(vett2), "second_item");
    pItem elem3 = readItem(vett3, sizeof(vett3), "third_item");
    pItem elem4 = readItem(vett3, sizeof(vett3), "forth_item");
    pItem elem5 = readItem(vett3, sizeof(vett3), "fifth_item");
    pItem elem6 = readItem(vett3, sizeof(vett3), "sixth_item");
    
    plinkedList list1 = createList();
    plinkedList list2 = createList();

    printf("%d %d\n", getNumber(list1), getNumber(list2));

    insertHead(list1, elem1);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertHead(list1, elem2);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertHead(list1, elem3);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertHead(list1, elem4);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertHead(list1, elem5);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertHead(list1, elem6);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertHead(list1, elem1);
     printf("%d %d\n", getNumber(list1), getNumber(list2));



    insertTail(list2, elem1);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertTail(list2, elem2);
     printf("%d %d\n", getNumber(list1), getNumber(list2));
    insertTail(list2, elem3);
     printf("%d %d\n", getNumber(list1), getNumber(list2));

    printList(list1);
    printList(list2);

    pItem *result = malloc(sizeof(*result));
    int *k = malloc(sizeof(*k));
    int numb;

    numb = searchKey(list1, "first_item", &result, FALSE);

    if (numb != -1){
        for (int i = 0; i < numb; i++)
        {
            printKey(getKey(result[i]));
        }
    } else
    {
        printf("No matches for the key %s\n","first_item");
    }

    deleteKey(list1, "first_item");
    

    destroyList(&list1);
    destroyList(&list2);

    destroyItem(&elem1);
    destroyItem(&elem2);
    destroyItem(&elem3);


    return 0;
}
