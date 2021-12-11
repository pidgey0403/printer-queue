#include "headers.h"
/*helper method that generates the actual request priority of a document*/
void requestPriority(int *priority){
    if (*priority <= 10){ //10% chance for the priority to be 1
        *priority=1; //high priority
    } else if(*priority<=80){ //70% chance for the priority to be 2
        *priority=2; //medium priority
    } else{ //20% chance for priority to be 3
        *priority=3; //low priority
    }
}
