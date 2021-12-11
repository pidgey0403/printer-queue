#include "headers.h"
/*debug method that prints a message as the printer incrementally prints out the current active document*/
void debugPrintProcess(NODE* node){
#if DEBUG_PRINT_PROCESS //preprocessor switch to control output of function
    //print out the currently printed document
    printf("PRINTING - DOCUMENT: %d   PAGE: %d   PRIORITY: %d   \n",((PRINTJOB*)node->dataPtr)->docNum,
           ((PRINTJOB*)node->dataPtr)->pageNums, ((PRINTJOB*)node->dataPtr)->requestPri);
#endif //DEBUG_PRINT_PROCESS
}
