#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void F() 
{//Preguntar orden correcto
    if(fork() == 0){
        int res = wait(NULL);
        printf("id: %d, pid: %d\n",getpid(),getppid());
    }

    if(fork() == 0){
        int res = wait(NULL);
        printf("id: %d, pid: %d\n",getpid(),getppid());
    }
    printf("F id: %d\n",getpid());
    return;
}

int main() 
{
    F();
    int res = wait(NULL);
    printf("Id: %d \n",getpid() );
    exit(0);
}
