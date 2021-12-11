#include "headers.h"
/*increment documents cycle counters after each cycle has passed*/
void incrementCycles(LIST* list){
    NODE* cur = list->head; //set cur node to the queue's head node
    while(cur!=NULL){ //while cur node is not pointing to empty queue
        ((PRINTJOB *)cur->dataPtr)->numCycles+=1; //increment the documents numCycles field
        if (((PRINTJOB *)cur->dataPtr)->numCycles > MAXCYCLES){ //if the documents numCycles exceeds MAXCYCLES
            if (DEBUG_SHOW_EXCEEDED){ //and if debug switch is on, then print the error message below
                printf("EXCEEDED CYCLE COUNT - Document: %d    Pages: %d    Priority: %d    Cycle Count: %d    \n",
                       ((PRINTJOB *)cur->dataPtr)->docNum, ((PRINTJOB *)cur->dataPtr)->pageNums,
                       ((PRINTJOB *)cur->dataPtr)->requestPri, ((PRINTJOB *)cur->dataPtr)->numCycles);
            }
        }
        cur=cur->next; //increment through entire queue to update all numCycle counters
    }
}