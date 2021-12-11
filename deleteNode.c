#include "headers.h"
/*delete a specified node in the linked list*/
void deleteNode(LIST* list, NODE* key){
    NODE *cur, *prev; //create NODE pointers cur and prev (current and previous trackers)
    for (cur=list->head, prev=NULL; cur!=NULL && cur->dataPtr!=key->dataPtr; prev=cur,cur=cur->next){
    } //iterate through the linked list, while the KEY node is not found
    if (cur==NULL){
        printf("Error: queue empty"); //if queue is empty then cur pointer will be NULL, so return error message
    }
    else if (prev==NULL){ //if document to be located is at the front of the queue
        list->head=cur->next; //delete node from head of list
    }else{
        prev->next=cur->next; //else relink nodes to remove the located document
    }
}

