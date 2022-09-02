#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
  int status;
  int i;


  char *cat_args[] = {"cat", "test.txt", NULL};
  char *grep_args[] = {"grep", "hola", NULL};
  char *wc_args[] = {"wc",NULL};

  int pipes[4];
  pipe(pipes); 
  pipe(pipes + 2); 

  // 4 descriptores asociados a 2 pipes, cada uno con descrp. para lectura y escritura
  // pipes[0] = lee de un pipe (grep lee)
  // pipes[1] = escribe en un pipe (cat escribe)
  // pipes[2] = lee de un pipe (wc lee)
  // pipes[3] = escribe en un pipe (grep escribe)

  // Note that the code in each if is basically identical, so you
  // could set up a loop to handle it.  The differences are in the
  // indicies into pipes used for the dup2 system call
  // and that the 1st and last only deal with the end of one pipe.

  
  if (fork() == 0)
    {
      // reemplaza salida estandar de cat con escritura en primer pipe
      dup2(pipes[1], 1);

      // proceso cierra todos los pipes, ya que se copio con dup2

      close(pipes[0]);
      close(pipes[1]);
      close(pipes[2]);
      close(pipes[3]);

      execvp(*cat_args, cat_args);
    }
  else
    {
      // hijo que ejecuta grep 
      if (fork() == 0)
	{
          // reemplaza entrada estandar de grep con lectura en primer pipe
	  dup2(pipes[0], 0);

          // reemplaza salida estandar de grep con escritura en segundo pipe
	  dup2(pipes[3], 1);

	  // proceso cierra todos los pipes
	  close(pipes[0]);
	  close(pipes[1]);
	  close(pipes[2]);
	  close(pipes[3]);

	  execvp(*grep_args, grep_args);
	}
      else
	{
	  // crea tercer proceso que ejecuta wc
	  if (fork() == 0)
	    {
	      // replace cut's stdin with input read of 2nd pipe
             // reemplaza entrada estandar de wc con lectura en segundo pipe

	      dup2(pipes[2], 0);

	      close(pipes[0]);
	      close(pipes[1]);
	      close(pipes[2]);
	      close(pipes[3]);

	      execvp(*wc_args, wc_args);
	    }
	}
    }
      
  // padre solo espera por hijos y cierra todos los pipes porque no los usa
  
  close(pipes[0]);
  close(pipes[1]);
  close(pipes[2]);
  close(pipes[3]);

  for (i = 0; i < 3; i++)
    wait(&status);
}
