#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

char *c[] = {"ls", "-l", 0};
char *c2[] = {"sort", "-n", "-k", "5", 0};

int main(){
    int p[2];
    pipe(p); // crea pipe (valores de descrp a partir de 3 dado 0 es entrada estandar, 1 salida, 2 error

    if (fork() == 0) {
    // hijo 
        close(0); // no lee  
        dup(p[0]); // copia descriptor para lectura a p[0].

        close(p[1]); // cierra escritura
     //   close(p[0]);
	execvp(c2[0],c2);
    } else {
        close(1); // no escribe 
        dup(p[1]);
        close(p[0]); // cierra lectura 
        close(p[1]); // Cierra escritura luego de escribir o el hijo no termina.
	execvp(c[0],c);
    }
}
