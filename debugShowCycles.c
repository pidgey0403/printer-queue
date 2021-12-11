#include "headers.h"
/*debug function that prints out a list of all documents in printer queue, after it has been incremented*/
void debugShowCycles(LIST* list){
#if DEBUG_SHOW_CYCLES //preprocessor control switch to determine function output
    for (NODE *node = list->head; node!=NULL;node=node->next){ //iterate through the printer queue and print out all documents that exist
        printf("Increment Cycle - Document: %d   Pages: %d   Priority: %d   Cycle Count: %d   \n",
               ((PRINTJOB*)node->dataPtr)->docNum, ((PRINTJOB*)node->dataPtr)->pageNums,
               ((PRINTJOB*)node->dataPtr)->requestPri, ((PRINTJOB*)node->dataPtr)->numCycles);
    }
#endif //DEBUG_SHOW_CYCLES
}