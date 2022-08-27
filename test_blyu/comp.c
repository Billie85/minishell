#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
int A(void);
int B(void);

int a;
int b;

int main(int argc, char *argv[])
{
    (void)argc;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (A() && B())
    {}
    TEST_
    if (A() || B())
    {}
}

int A(void)
{
    TEST
    return(a);
}

int B(void)
{
    TEST
    return(b);
}

/* 
blyu@ryonoMacBook-Air test_blyu % cc comp.c
blyu@ryonoMacBook-Air test_blyu % ./a.out 0 1
[(comp.c/23) A ]
---------------------------------------------[(comp.c/16) main ]
[(comp.c/23) A ]
[(comp.c/29) B ]
blyu@ryonoMacBook-Air test_blyu % ./a.out 1 1
[(comp.c/23) A ]
[(comp.c/29) B ]
---------------------------------------------[(comp.c/16) main ]
[(comp.c/23) A ]
blyu@ryonoMacBook-Air test_blyu % ./a.out 1 0
[(comp.c/23) A ]
[(comp.c/29) B ]
---------------------------------------------[(comp.c/16) main ]
[(comp.c/23) A ]
blyu@ryonoMacBook-Air test_blyu % cc -Wall -Wextra -Werror comp.c
blyu@ryonoMacBook-Air test_blyu % ./a.out 0 1
[(comp.c/24) A ]
---------------------------------------------[(comp.c/17) main ]
[(comp.c/24) A ]
[(comp.c/30) B ]
blyu@ryonoMacBook-Air test_blyu % ./a.out 1 1
[(comp.c/24) A ]
[(comp.c/30) B ]
---------------------------------------------[(comp.c/17) main ]
[(comp.c/24) A ]
blyu@ryonoMacBook-Air test_blyu % ./a.out 1 0
[(comp.c/24) A ]
[(comp.c/30) B ]
---------------------------------------------[(comp.c/17) main ]
[(comp.c/24) A ]
blyu@ryonoMacBook-Air test_blyu % 
 */