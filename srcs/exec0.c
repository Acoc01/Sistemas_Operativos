#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid < 0) { // fork fallo
        printf("fork fallo\n");
        exit(1);
    } else if (pid == 0) { //hijo
        printf("Soy hijo H: %d mi padre P : %d\n", getpid(), getppid());
        char *myargs[4];
        myargs[0] = strdup("wc");   // programa: "wc" 
        myargs[1] = strdup("-l"); // argumento para wc
        myargs[2] = strdup("fork0.c"); // argumento para wc
        myargs[3] = NULL;           // no mas argumentos para wc 
        execvp(myargs[0], myargs);  // cambia imagen de hijo a wc  
        printf("Aqui llegaría solo ante el error de execvp\n");
    } else { // padre
        int res = wait(NULL);
        printf("Soy padre P: %d mi mi Hijo : %d o res %d \n", getpid(), pid, res);
    }
    printf("FIN proc actual %d\n", getpid());
    return 0;
}

