#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "debug.h"

int main(void)
{
    char *line = NULL;
    while (1)
    {
        line = readline("> ");
        printf("line is '%s'\n", line);
        add_history(line);
        rl_on_new_line();
        free(line);
    }
    printf("exit\n");
    return 0;
}