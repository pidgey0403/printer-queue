#include "headers.h"
/*inserts a document into the printer queue in a sorted manner - first considering request priority and then page numbers*/
/*this inserts documents in ascending order of priority; if priority of the document matches pre-existing documents,
 * it then sorts based on ascending order of page numbers. */
void sortedInsert (LIST* list, void* itemPtr){
    NODE *cur, *newNode; //create cur and newNode NODE pointers
    if((newNode = (NODE*)malloc(sizeof(NODE)))){ //if able to successfully allocate memory for the newNode pointer
        newNode->dataPtr = itemPtr; //assign newNodes data pointer to the passed itemPoint (assign the node's data field to a document)
        //if the queue is empty OR the request priority of the head document is greater than the req priority of the to be inserted document
        if (list->head == NULL || ((PRINTJOB*)list->head->dataPtr)->requestPri > ((PRINTJOB *)newNode->dataPtr)->requestPri){
            newNode->next=list->head; //place the new document to the left of the head document
            list->head = newNode;
            list->count++; //increment count
            debugAdding(newNode); //check of debug message is required
        }else{
            cur = list->head; //assign cur pointer to the queue's head document
            //iterate through the queue until the request priority of the cur document is LESS than that of the new document
            while(cur->next!=NULL && ((PRINTJOB*)cur->next->dataPtr)->requestPri < ((PRINTJOB*)newNode->dataPtr)->requestPri){
                cur=cur->next;
                //if the request priority of both are equal
                if (cur->next!=NULL && ((PRINTJOB*)cur->next->dataPtr)->requestPri == ((PRINTJOB*)newNode->dataPtr)->requestPri){
                    //then while the page numbers of the cur document are less than or equal to that of the new document,
                    while(cur->next!=NULL && ((PRINTJOB*)cur->next->dataPtr)->pageNums <= ((PRINTJOB*)newNode->dataPtr)->pageNums){
                        cur=cur->next; //iterate through the queue
                    }
                    newNode->next=cur->next; //place the new document to the right of the located document
                    cur->next=newNode;
                    list->count++; //increment queue document counter
                    debugAdding(newNode); //check if debug message for the new document is required
                }
            }
        }
    }
}
