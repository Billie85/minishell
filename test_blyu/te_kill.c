#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_action(int sig)
{
    (void)sig;
    printf("sig\n");
    kill(0, sig);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, sig_action);
    while (1)
    {
        pause();
    }
    return 0;
}
