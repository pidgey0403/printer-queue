#include "headers.h"
/*checks if the printer is empty and assigns it the highest priority document to print it out*/
void printerProcess(LIST* sList) {
    static NODE* printer; //make static pointer called printer
    if (printer == NULL && sList->head!=NULL){ //if the printer is null and the queue is not empty
        printer=sList->head; //assign the printer the topmost document in the queue
        deleteNode(sList,printer); //remove the topmost document rom the queue
    }
    if (printer != NULL) { //if the printer is currently printing a document
        if ((((PRINTJOB *) printer->dataPtr)->pageNums) > 0){ //if the documents page number is greater than 0 (not finished printing)
            (((PRINTJOB *) printer->dataPtr)->pageNums) -= PAGESPERMINUTE; //print out PAGESPERMINUTE pages of the document
            debugPrintProcess(printer); //check if debug message is required for the currently printing document
        }
        if ((((PRINTJOB *) printer->dataPtr)->pageNums) <= 0) { //if the document is finished printing, print out a completion message
            printf("Print Job Completed - Document Number: %d - Cycle Count: %d\n",((PRINTJOB*)printer->dataPtr)->docNum, ((PRINTJOB*)printer->dataPtr)->numCycles);
            printer = NULL; //set the printer to NULL (empty and ready for a new document)
        }
    }
}

