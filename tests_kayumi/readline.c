#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
        char *inpt;

        int i = 0;

        while ( i < 10 )
        {
                inpt = readline("Enter text: ");
                add_history(inpt);
                printf("%s", inpt);
                printf("\n");
                ++i;
        }
        return 0;
}
//readlineの役割として、ラインエディタというものの一種で、ライブラリとして配布されています。
//その名の通り、ライン(行)をエディタ(編集するもの)という意味で、一般的にシェルがコマンドを受け付けるところで使われています。
//windowsの場合コンパイルをするのに -lreadlineを付ける必要がある。