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

int counter = 5;

void sig_handler(int sig) {
    if(sig == SIGCHLD){
    	printf("llega senal de fin hijo\n");
    } else if(sig == SIGALRM){
    	printf("llega senal de alarma\n");
	exit(0);
    }
}

int main() {
    signal(SIGCHLD, sig_handler);
    signal(SIGALRM, sig_handler);

    printf("%d", counter);
    fflush(stdout);
    pid_t pid;
    for(int i=0; i<2; i++){
       if ((pid = fork()) == 0) {
		printf("creado\n");
		exit(0);
       }
    }
    alarm(10);
    while(1);
}
