#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int counter = 1;

int main() 
{
    if (fork() == 0) {
	counter--;  
	//exit(0);
    }
    //printf("counter = %d\n", counter);
    wait(NULL); 
    printf("counter = %d\n", counter);
}
