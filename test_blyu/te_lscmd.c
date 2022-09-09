#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "debug.h"

void child(char *arg[], char *env[]);

int main(int argc, char *argv[], char *env[])
{
    pid_t pid;
    char *arg[3];
    int   r; 
 
    arg[0] = "/bin/ls";
    arg[1] = "nofile";
    arg[2] = NULL;
    pid = fork();
    if (!pid)
        child(arg, env);
TESTn(wait(&r))
TESTn(r)
	return (0);
}

void child(char *arg[], char *env[])
{
TESTn(getpid())
	execve("/bin/ls", arg, env);
    exit(42);
}
