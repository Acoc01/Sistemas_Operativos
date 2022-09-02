#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void F() 
{
    if (fork() == 0) {
	fork();
	printf("F: %d, p: %d\n",getpid(),getppid());
    }
    printf("HP: %d\n",getpid());
    return;
}

int main() 
{
    F();
    printf("M: %d\n",getpid());
    exit(0);
}
