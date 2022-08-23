#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

int main(void)
{
    char line[256];

    while (1)
    {
        bzero(line, 256);
        read(0, line, 256);
        printf("line is '%s'\n", line);
        add_history(line);
    }
    printf("exit\n");
    return 0;
}