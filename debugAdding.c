#include "headers.h"
/*debug method that prints a message when a document is being added to the printer queue*/
void debugAdding(NODE* node){
#if DEBUG_ADDING  //use #if and #endif to control function using preprocessor command
    printf("Adding to Queue - Doc: %d  NoPages: %d Priority: %d\n", ((PRINTJOB *)node->dataPtr)->docNum,
        ((PRINTJOB *)node->dataPtr)->pageNums, ((PRINTJOB *)node->dataPtr)->requestPri);
#endif //DEBUG_ADDING
}




