#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid, ppid;
    
    pid = fork();

    if (pid == 0) 
	{
        printf("Child process: PID = %d\n", getpid());
        printf("Child process: Parent PID = %d\n", getppid());
    } 
	else if (pid > 0) 
	{
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent process: Parent PID = %d\n", getppid());
    } 
	else 
	{
        printf("Error in creating new process\n");
    }

    return 0;
}
