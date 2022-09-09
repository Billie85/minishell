#include "debug.h"
#include <stdlib.h>
int main (int argc, char *argv[])
{
    (void)argc;
    return (atoi(argv[1]));
}

/* 
bash-3.2$ ./a.out 3
bash-3.2$ echo $?
3
bash-3.2$ ./a.out 255
bash-3.2$ echo $?
255
bash-3.2$ ./a.out 256
bash-3.2$ echo $?
0
bash-3.2$ ./a.out 255
 */

/* int main (int argc, char *argv[])
{
    while (1)
    {}
    return (atoi(argv[1]));
} */