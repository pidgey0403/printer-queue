#include "headers.h"
/*get the number of documents in the printer queue*/
int counters(LIST* list){
    int count = 0;
    for (NODE *temp = list->head; temp!=NULL;temp=temp->next){ //loop through queue list and increment count for every node
        ++count;
    }
    return count; //return int variable that stores count of items in list
}
