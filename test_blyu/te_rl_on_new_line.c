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
    printf ("\n");
    rl_on_new_line();
    rl_add_undo(UNDO_DELETE, 0, 6, strdup("hello "));
    unsigned char c[9];
    c[0] = 0xff;
    c[1] = 0xff;
    c[2] = 0xff;
    c[3] = 0xff;
    c[4] = 0xff;
    c[5] = 0xff;
    c[6] = 0xff;
    c[7] = 0xff;
    c[8] = 0x0;
    rl_replace_line((char *)c, 1);
    rl_redisplay();
}
int main()
{
    signal(SIGINT, sig_handler);
    while (1)
    {
        //TEST
        char *str = readline(">");
        if (str)
        {
            add_history(str);
		    printf("%s\n",str);
            free(str);
        }
        else
            printf("readline retun null\n");
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