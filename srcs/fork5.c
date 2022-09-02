#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void F() 
{
    if (fork() == 0) {
	fork();
    int res = wait(NULL);
	printf("F: %d p: %d\n",getpid(),getppid());
	exit(0);
    }
    return;
}

int main() 
{
    F();
    int res = wait(NULL);
    printf("M: %d\n",getpid());
    exit(0);
}
