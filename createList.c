#include "headers.h"
/*create the linked list which will act as the printer queue*/
LIST* createList(void){
    LIST* list; //create LIST* pointer list
    list= (LIST*) malloc (sizeof (LIST)); //dynamically allocate memory for list
    if (list){ //if we can successfully allocate memory (no errors/out of memory)
        list->head = NULL; //initialize head node of list to NULL
        list->count = 0; //initialize list's count to 0
    }
    return list; //return the list pointer
}