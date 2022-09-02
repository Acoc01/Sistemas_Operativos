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

void sig_handler(int sig) // manejador de signals
{
    printf("llega SIGINT\n");               
    exit(0);                                
}                                          

int main() 
{
    
    signal(SIGINT, sig_handler);  // instala rutina para control-C
    pause(); //espera por evento
    
    exit(0);
}
