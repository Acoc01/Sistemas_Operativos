#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int x = 1;

    pid_t pid = fork(); 
    if (pid == 0) {  // hijo
	exit(0);
    }
    else if(pid > 0){ // padre, pid contiene pid hijo
	for(int a=0; a<1000; a++)
	   printf("n");
	sleep(10);
    } else {
    	printf("error en fork\n"); 
	exit(1);
    }
}
