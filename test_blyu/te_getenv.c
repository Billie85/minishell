#include <stdlib.h>
#include "debug.h"

int main (int argc, char *argv[])
{
    char *env = getenv(argv[1]);
    TESTp(env);
    TESTs(env);
    //TESTp(getenv(argv[1]));
    return 0;
}

/* 
blyu@ryonoMacBook-Air test_blyu % cc  te_getenv.c
blyu@ryonoMacBook-Air test_blyu % ./a.out 
[(te_getenv.c/7) main ]env:0x0
[(te_getenv.c/8) main ]env:(null)
[(te_getenv.c/9) main ]getenv(argv[1]):0x0
blyu@ryonoMacBook-Air test_blyu % ./a.out TERM
[(te_getenv.c/7) main ]env:0x16f59fe1a
[(te_getenv.c/8) main ]env:xterm-256color
[(te_getenv.c/9) main ]getenv(argv[1]):0x16f59fe1a
blyu@ryonoMacBook-Air test_blyu % ./a.out PWD 
[(te_getenv.c/7) main ]env:0x16f3f796d
[(te_getenv.c/8) main ]env:/Users/blyu/Desktop/minishell/test_blyu
[(te_getenv.c/9) main ]getenv(argv[1]):0x16f3f796d
blyu@ryonoMacBook-Air test_blyu % 
 */