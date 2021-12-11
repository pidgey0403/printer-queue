#include "headers.h"
/*create the document(single node) and insert it into the printer queue  in order of priority and page number*/
void createDocument(PRINTJOB *newDataP, LIST* list, int priType, int pages, int numCycles){
    if (newReqProc()==1) { //if 10% chance to make a new document achieved
        PRINTJOB *p = (PRINTJOB *) malloc(sizeof(PRINTJOB)); //dynamically allocate memory for a pointer to structure that is the document
        requestPriority(&priType); //call request priority helper function, to get the document priority
        p->docNum = list->count + 1; //set document's number to the queue counter+1
        p->requestPri = priType; //set document's request priority
        p->pageNums = pages; //set document's page number to randomly generate page#
        p->numCycles = numCycles; //set document's number of cycles to passed value

        newDataP = (PRINTJOB *) malloc(sizeof(PRINTJOB));  //dynamically allocated a document (PRINTJOB) pointer
        *newDataP = *p; //newdataP points to p pointer
        sortedInsert(list, newDataP); //call sortedInsert() function to insert the new document into printer queue, in order
        free(p); //free the document pointer
    }
}