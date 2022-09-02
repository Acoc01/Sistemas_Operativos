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
#include <errno.h>

void sig_handler(int sig) {
    if(sig == SIGCHLD){
        printf("llega senal de fin hijo\n");
        exit(0);
    }
}

int main() {
    signal(SIGCHLD, sig_handler);


    int status, i;
    pid_t pid;


    // padre crea hijos
    for (i = 0; i < 2; i++)                       
	if ((pid = fork()) == 0){ 
	        char *myargs[4];
        	myargs[0] = strdup("sleep");   // programa: "wc" 
        	myargs[1] = strdup("10"); // argumento para wc
        	myargs[2] = NULL;           // no mas argumentos para wc 
        	execvp(myargs[0], myargs);  // cambia imagen de hijo a wc  
	    exit(100+i);                         
	}

    //padre espera por todos sus hijos, -1 cualquiera
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) { 
	if (WIFEXITED(status))                  
	    printf("hijo %d termina bien con estado =%d\n",
		   pid, WEXITSTATUS(status));     
	else
	    printf("hijo %d termina mal\n", pid);
    }
    printf(" Padre sigue funcionando\n");
    while(1);

    // No me quedan hijos
    if (errno != ECHILD) 
	printf("error hijo\n");

    exit(0);
}
