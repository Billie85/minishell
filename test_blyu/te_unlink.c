#include <unistd.h>
#include "debug.h"

int main(int argc, char *argv[])
{
    TESTn(unlink(argv[1]))
    TESTn(unlink("not_exit_file"))
    return 0;
}

/* 
blyu@ryonoMacBook-Air test_blyu % cc  te_unlink.c
blyu@ryonoMacBook-Air test_blyu % ./a.out buf.txt
[(te_unlink.c/6) main ]unlink(argv[1]):0
[(te_unlink.c/7) main ]unlink("not_exit_file"):-1
blyu@ryonoMacBook-Air test_blyu % 
 */