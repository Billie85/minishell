#include "minishell.h"

void sigint_handler(int sig)
{
    (void)sig;
    if (0/* もし、コマンドの実行中に発生した場合、その関数にSIGINTを送る*/)
    {
        printf("^C\n");
    }
    else
    {
        printf ("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
    return ;
}


void sigquit_handler(int sig)
{
    (void)sig;
    if (0/* もし、コマンドの実行中に発生した場合、その関数にSIGQUITを送る*/)
    {
        printf("^\\\n");
    }
    return ;
}