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
    if(sig == SIGUSR1){ // Preguntar SIGUSR1
    	counter = counter - 1;
    	printf("llega senal de usr1 %d", counter);
    	fflush(stdout); 
    } else if(sig == SIGCHLD){
    	printf("llega senal de fin hijo\n");
    	exit(0);
    }
}

int main() {
    signal(SIGUSR1, sig_handler);
    signal(SIGCHLD, sig_handler);

    printf("%d", counter);
    fflush(stdout);
    pid_t pid;
    for(int i=0; i<5; i++){
       if ((pid = fork()) == 0) {
		printf("creado\n");
		sleep(2);
		exit(0);
       }
    }
    kill(pid, SIGUSR1); 
    waitpid(-1, NULL, 0);
    counter = counter + 1;
    printf("%d", counter);
    exit(0);
}
