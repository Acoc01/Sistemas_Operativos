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


void sig_handler(int sig) 
{
    static int c = 0;

    printf("Expira tiempo \n");
    if (++c < 5)  
	alarm(1); // vuelve a setear alarma en 1 seg
    else {
	printf("Listo!\n");
	exit(0);
    }
}

int main() 
{
    signal(SIGALRM, sig_handler); // Le dice a sistema la funcion que atiende SIGALRM
    alarm(1); // setea alarma para que avise en 1s 

    while (1) {
	;  // Manejador retorna control aqui cada vez que ocurre
    }
    exit(0);
}

