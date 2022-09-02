#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

//行を履歴のリストに保存する
int main()
{
    char *line = NULL;

    while (1)
    {
        line = readline("> ");
        if (line == NULL || strlen(line) == 0)
        {
            free(line);
            break;
        }
        printf("line is '%s'\n", line);
        add_history(line);
		//add_history関数を入れるとヒストリーの参照ができる。
		//読み取った行の履歴を保存してくれる。
        free(line);
    }
    printf("exit\n");
    return 0;
}