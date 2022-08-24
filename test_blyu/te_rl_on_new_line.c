//tell the update routines that we have moved onto a new line
//通常、改行を出力した後、新しい (空の) 行に移動したことを更新ルーチンに伝えます。

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

void sig_handler()
{
    //TEST
    printf ("  ");
    //rl_on_new_line();
    rl_replace_line("hello", 0);
    //rl_redisplay();
}
int main()
{
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, sig_handler);
    while (1)
    {
        //TEST
        char *str = readline(">");
		printf("%s\n",str);
        //TEST
    }
}

/* 
int main()
{
    while (1)
    {
        TEST(rl_on_new_line())
        rl_replace_line("hello", 0);
        rl_redisplay();
        STOP
    }
    return 0;
}  */