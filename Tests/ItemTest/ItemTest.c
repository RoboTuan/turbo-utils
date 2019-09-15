// To-do:
// fix output beacuse it's not in order

#include <stdio.h>
#include <string.h>
#include "../../DataStructures/Item/item.h"

int main(void){
    pItem elem1, elem2, elemVoid = NULL;
    int vett_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char vett_char[] = "home";
    char name1[] = "Integer vector";
    char name2[] = "Char vector";

    elem1 = readItem(vett_int, sizeof(vett_int), name1);
    elem2 = readItem(vett_char, sizeof(vett_char), name2);

    
   

   // Check if itemCheckVoid operates properly on NULL items
   if (!itemCheckVoid(elemVoid))
    {
      fprintf(stderr, "%s\n", "The itemCheckVoid funciton not defined properly, it should fail");
      return 1;
    }
    fprintf(stdout, "%s\n", "The item elemVoid is correctly identified as NULL item");
   

   // Check if itemCheckVoid operates properly on NOT NULL items
   if (itemCheckVoid(elem1) || itemCheckVoid(elem2))
   {
       fprintf(stderr, "%s and %s %s\n", getKey(elem1), getKey(elem2), "not defined");
       return 1;
   }


   // Check if ferKey operates properly
   if (strcmp(getKey(elem1), name1) != 0 || strcmp(getKey(elem2), name2) != 0)
   {   
       fprintf(stderr,"%s\n", "Error in getKey function (item.c)");
       return 1;
    }

   destroyItem(&elem1);
   destroyItem(&elem2);

   itemCheckVoid(elem1);
   itemCheckVoid(elem2);
    
    return 0;
}