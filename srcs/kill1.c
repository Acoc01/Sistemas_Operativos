#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() 
{
    pid_t pid;

    // hijo duerme hasta que recibe SIGKILL   
    if ((pid = fork()) == 0) {   
	printf("hijo espera signal\n");
	pause();  // espera por signal  
	printf("No deberia llegar aqui\n");
	exit(0);
    }

    sleep(5);
    // padre envia kill a hijo
    kill(pid, SIGKILL);
    exit(0);
}
