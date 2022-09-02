#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void F() 
{
    if (fork() == 0) {
	fork();
	printf("F\n");
	return;
    }
    return;
}

int main() 
{
    F();
    printf("M\n");
    exit(0);
}
