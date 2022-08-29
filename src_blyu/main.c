#include "minishell.h"
int g_;
int exeret = 0;

int main(int argc, char *argv[])
{
    preexe();
    if (argc == 1)
        shell_loop();
    return (0);
}

void preexe(void)
{
    struct termios s;

    g_ = NEXE;
    tcgetattr(STDIN_FILENO, &s);
    s.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigint_handler);
    return ;
}