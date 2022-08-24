#include <unistd.h>
#include <stdlib.h>
#include "debug.h"
int main(void)
{
    char *name = ttyname(0);
    TESTp(name)
    TESTs(name)
    name = ttyname(1);
    TESTp(name)
    TESTs(name)
    name = ttyname(2);
    TESTp(name)
    TESTp(name)
    TESTs(name)
    name = ttyname(3);
    TESTp(name)
    TESTs(name)
    return 0;
}