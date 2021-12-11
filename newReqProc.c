#include "headers.h"
/*helper function that returns the request priority for a document*/
int newReqProc(){
    return rand() % (10) + 1; //value between 1 and 10
}

