#include "headers.h"
/*helper function that returns a randomly generate number of pages for the document*/
int pages(){
    return rand() % (MAXPAGES)+1; //value between 1 and MAXPAGES
}