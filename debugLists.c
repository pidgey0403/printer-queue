#include "headers.h"
/*debug method that prints out a list of all documents in the printer queue*/
void debugLists(LIST* list){
#if DEBUG_LIST //preprocessor switch to turn function output on/off
    if (list->head==NULL){ //if the printer queue is empty (no documents) print out empty queue message
        printf("EMPTY QUEUE - no print jobs currently in queue\n");
    } else{ //if printer queue isn't empty
        printf("Current Printer Queue Size: %d\n", counters(list)); //call helper function and print the size of queue
        NODE *temp; //create temporary pointer of type NODE (structure)
        for (temp= list->head; temp!=NULL;temp=temp->next){ //iterate through the printer queue and print out all documents
            printf("Current Printer Queue : DocNum: %d  NumofPages %d  PriorityLevel %d  NumOfCycles %d \n",
                   ((PRINTJOB *)temp->dataPtr)->docNum, ((PRINTJOB *)temp->dataPtr)->pageNums,
                   ((PRINTJOB *)temp->dataPtr)->requestPri, ((PRINTJOB *)temp->dataPtr)->numCycles);
        }
        printf("END OF LIST\n");
    }
#endif //DEBUG_LIST
}
