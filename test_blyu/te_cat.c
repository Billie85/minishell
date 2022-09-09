#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "debug.h"

void child(char *arg[], char *env[]);

int main(int argc, char *argv[], char *env[])
{
    pid_t pid;
    char *arg[3];
    int   r; 
 
    arg[0] = "/bin/cat";
    arg[1] = NULL;
    pid = fork();
    if (!pid)
        child(arg, env);
    sleep(1);
    kill(pid, SIGINT);
TESTn(wait(&r))
TESTn(r)
	return (0);
}

void child(char *arg[], char *env[])
{
TESTn(getpid())
	execve("/bin/cat", arg, env);
    exit(42);
}
/* 
bash-3.2$ cc te_cat.c 
bash-3.2$ ./a.out 
[(te_cat.c/29) child ]getpid():6049
[(te_cat.c/22) main ]wait(&r):6049
[(te_cat.c/23) main ]r:2
bash-3.2$ cat 
^C
bash-3.2$ echo $?
130
bash-3.2$ 
-------------------------------------
130 == 0b10000010
 */