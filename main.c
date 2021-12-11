#include "headers.h"
/*main function largely responsible for control of execution of program*/
int main() {
    //variable initialization required for program
    srand(time(NULL)); //seed srand() with NULL - unique random values
    PRINTJOB *newDataP; //declare newDataP pointer of type PRINTJOB (document structure)
    LIST* sList; //declare queue pointer 'sList' of type LIST
    sList = createList(); //initialize the empty linked linked (printer queue) and assign to sList
    static int numCycles; //declare static int numCycle - tracks number of cycles document has been in queue

    for (int cycle = 0; cycle < ITERATIONS; cycle++){
        printf("\nIteration #: %d\n",cycle); //print cycle number
        createDocument(newDataP, sList, priType(), pages(), numCycles); //create new document and insert into queue
        debugLists(sList); //check if debug message to print documents in queue (before incrementation) is required
        printerProcess(sList); //check if printer is empty, pop off front document and print it if so, otherwise let printer continue to print
        incrementCycles(sList);    //increment number of cycles that a document has been in the queue
        debugShowCycles(sList); //check if debug message to print documents in queue is required
    }
    programEnd(sList); //print the ending program messages
    free(sList); //free the linked list
    return 0;
}
