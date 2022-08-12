#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void PressEnter (void)
{
    printf("Press enter to begin");
    char enter = 0;
    while ((enter != '\r') && (enter != '\n')) 
    { 
            enter = getchar(); 
    }
}
 
 void randomnumber (void)
 {
    int random;
    //requires "srand (time(0));", normally in main function
    srand (time(0));
    random=(rand() % 10);
 }
 
 void time (void)
{
 clock_t start = clock();
 float timeTaken =( (clock() - start) /(60 * CLOCKS_PER_SEC));
}