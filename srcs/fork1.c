#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int x = 1; //No comparten la variable

    pid_t pid = fork(); 
    if (pid == 0) {  // hijo
	x++;
	printf("hijo(%d) : x=%d\n", getpid(),x); 
	exit(0);
    }
    else if(pid > 0){ // padre, pid contiene pid hijo
        int res = wait(NULL);
	x--;
    	printf("padre(%d): x=%d\n", getpid(),x); 
    } else {
    	printf("error en fork\n"); 
	exit(1);
    }
    exit(0);
}
