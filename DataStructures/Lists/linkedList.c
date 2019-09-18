#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct node *link;

link newNode(pItem element);
//void destroyNode(pItem element);
void traverseList(link l);
void printNode(link l);

// Struct for the nodes
struct node{
    pItem value;
    link next;
    link prev;
};

// Wrapper struct for the list
struct linkedList{
    link head;
    link tail;
    // Number of items
    int n_items;
    // flag (TRUE or FALSE) for sorted or unsorted list
    int sorted;
};

// Create list allocating the resources.
plinkedList createList(void){
    plinkedList list = malloc(sizeof(*list));
    list->head = NULL;
    list->tail = NULL;
    list->n_items = 0;
    list->sorted = FALSE;
    return list;
}

// Inserts a new element (item) at the head of the list.
void insertHead(plinkedList list, pItem element){
    if (list->head == NULL){
        list->head = list->tail = newNode(element);
        (list->n_items)++;
    }
    else{
        link new_node = newNode(element);

        // Put head->prev equals to new_node, then put new_node->next 
        // equals to the ACTUAL (the last iserted item) head and finally put head equals to new_node
        (list->head)->prev = new_node;
        new_node->next = list->head;
        (list->head) = new_node;
        (list->n_items)++;
    }
}

// Inserts a new element (item) at the tail of the list.
void insertTail(plinkedList list, pItem element){
        if (list->tail == NULL){
        list->tail = list->head = newNode(element);
        (list->n_items)++;
    } else{
        link new_node = newNode(element);

        // Put tail->next equals to new_node, then put new_node->prev 
        // equals to tail and finally tail equals to new_node
        (list->tail)->next = new_node;
        new_node->prev = list->tail;
        (list->tail) = new_node;
        (list->n_items)++;
    }

}

// Creates a new node allocating the resources.
link newNode(pItem element){
    link tmp = malloc(sizeof(*tmp));
    if (tmp == NULL){
        fprintf(stderr,"%s\n", "Could not allocate node");
        exit(EXIT_FAILURE);
    }
    tmp->value = element;
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}

// Destroy the list deallocating the nodes and the list, 
// the items must be deallocate by the client.
void destroyList(plinkedList *list){
    link x;
    for (x = (*list)->head; x != NULL; x = x->next){
        free(x);
    }
    (*list)->n_items = 0;
    free(*list);
    (*list) = NULL;
}

// Gets the number of node in the list.
int getNumber(plinkedList list){
    return list->n_items;
}

// Prints the list, i.e. prints the name (the key) of the item of all the nodes
void printList(plinkedList list){
    link x;
    printf("\n");
    for (x = list->head; x != NULL; x = x->next){
        printNode(x);
    }
    printf("\n");
}

// Prints the name (the key) of the item of the node.
void printNode(link l){
    printf("%s\n",getKey(l->value));
}

// Returns the number of matches (the array must be allocated and deallocated by the user and
// it's passed to the function) of the key (name) provided in the list. 
// If the option FIRST_OCCURENCY is set tu TRUE, return the first match only (still an array).
// If there are no matches, return -1;
int searchKey(plinkedList list, pKey k, pItem **result, int FIRST_OCCURENCY){
    link x;
    int i = 0;
    int number_of_elements = 0;

    for (x = list->head; x != NULL; x = x->next){
        if (keycmp((char *) getKey(x->value), (char *) k) == 0){
            *result = realloc(*result, ++number_of_elements * sizeof(pItem));
            if (*result == NULL){
                fprintf(stderr,"%s\n", "Could not reallocate resources");
                fprintf(stderr,"%s\n", "The result of the searchKey function could not be reallocated");
                exit(EXIT_FAILURE);
            }
            
            (*result)[i++] = x->value;
        }
    }

    if (number_of_elements > 0){
        return number_of_elements;
    } else{
        return -1;
    }
}

void deleteKey(plinkedList list, pKey k){
    link x;
    int key_not_exists = TRUE;
    for ( x = list->head; x != NULL; x = x->next){
     if (keycmp(getKey(x->value), k) == 0)
        {   
            if (x == list->head){
                list->head = x->next;
                (list->head)->prev = NULL;
                free(x);
                (list->n_items)--;
                key_not_exists = FALSE;

            } else if (x == list->tail) {
                list->tail = x->prev;
                (list->tail)->next = NULL;
                free(x);
                (list->n_items)--;
                key_not_exists = FALSE;
                
            } else {
                (x->prev)->next = x->next;
                (x->next)->prev = x->prev;
                free(x);
                (list->n_items)--;
                key_not_exists = FALSE;
            }
        }      
    }
    if (key_not_exists){
        fprintf(stdout,"%s %s %s\n", "The key", k, " does not exists in the list");
    }   
}