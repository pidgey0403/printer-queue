#include "headers.h"
/*helper method that prints out the final print statements when the program is completed*/
void programEnd(LIST* list){
    printf("--------------------------------------");
    printf("\nEnd of program \n");
    printf("Number of printer jobs left in queue: %d\n", counters(list));
}