#include <stdio.h>
#include <unistd.h>

int main() 
{
    pid_t pid = fork(); // Si es distinto de 0 es equivalente al pid del hijo
    if(pid == 0){
	printf("if 0 pid = %d pid hijo %d\n",pid, getpid());
    } else if(pid > 0) {
	printf("if > pid = %d pid padre %d\n",pid, getpid());
    }
}
