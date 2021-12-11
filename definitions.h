#ifndef ASSIGNMENT_5_DEFINITIONS_H
#define ASSIGNMENT_5_DEFINITIONS_H

/*all structure definitions*/
typedef struct printJob{ //printJob structure - the template for all documents
    int docNum; //document number
    int requestPri; //request priority of each document
    int pageNums; //the page numbers that each document contains
    int numCycles; //number of cycles a document has been in the printer queue
} PRINTJOB; //PRINTJOB alias

typedef struct node{ //node structure - the nodes in the linked list
    void* dataPtr; //dataPtr of type void pointer - pointer to data fields
    struct node* next; //next pointer - next node after the current node
} NODE; //NODE alias

typedef struct LinkedList {  //the linkedlist structure
    NODE* head; //head node of linked list
    int count; //count - number of nodes in the linked list
} LIST; //LIST alias


/*all function prototypes with signatures*/
void requestPriority(int *priority);
LIST* createList(void);
void deleteNode(LIST* list, NODE* key);
void sortedInsert (LIST* list, void* itemPtr);
int counters(LIST* list);
void incrementCycles(LIST* list);
void debugLists(LIST* list);
void debugAdding(NODE* node);
void debugPrintProcess(NODE* node);
void debugShowCycles(LIST* list);
void printerProcess(LIST* sList);
void createDocument(PRINTJOB *newDataP, LIST* list, int priType, int pages, int numCycles);
void programEnd(LIST* list);
int newReqProc();
int priType();
int pages();

/*debug preprocessor definitions*/
#define DEBUG_LIST 1
#define DEBUG_ADDING 1
#define DEBUG_PRINT_PROCESS 1
#define DEBUG_SHOW_CYCLES 0
#define DEBUG_SHOW_EXCEEDED 0

/*required preprocessor definitions of constant values*/
#define PAGESPERMINUTE 1
#define MAXCYCLES 200
#define MAXPAGES 30
#define ITERATIONS 1000

#endif //ASSIGNMENT_5_DEFINITIONS_H
