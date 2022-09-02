#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int x = 3;

    if (fork() != 0)
	printf("A x=%d\n", ++x);

    printf("B x=%d\n", --x);
    exit(0);
}
