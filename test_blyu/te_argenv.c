#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char **env;

void showenv(int sig)
{
    (void)sig;
    while(*env)
    {
        printf("%s\n", *env++);
    }
    return ;
}

int main(int argc, char *argv[], char *envp[]) {
    (void)argc;
    (void)argv;
    env = envp;
    signal(SIGINT, showenv);
    while(1)
    {
        pause();
    }
    return 0;
}