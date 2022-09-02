#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int x = 1;

    if (fork() == 0)
	   printf("A : x=%d pid %d ppid %d\n", ++x, getpid(), getppid());
    printf("B : x=%d pid %d ppid %d\n", --x, getpid(), getppid());
    exit(0);
}
