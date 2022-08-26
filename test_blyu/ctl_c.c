# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
#include "debug.h"
#include <termios.h>

void sig_handler()
{
    printf ("\n");
    rl_on_new_line();
    rl_replace_line("", 1);
    rl_redisplay();
}
int main()
{
    signal(SIGINT, sig_handler);
    struct termios s;
    tcgetattr(STDIN_FILENO,&s);
    s.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
    while (1)
    {
        char *str = readline(">");
        TEST
        if (str)
        {
            add_history(str);
		    printf("%s\n",str);
            free(str);
        }
        else
            printf("readline retun null\n");
    }
}

