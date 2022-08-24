#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    
    if (access(argv[1], F_OK))
    {
        printf("the file not exit\n");
        return 0;
    }
    if (access(argv[1], R_OK))
        printf("-");
    else
        printf("r");
    if (access(argv[1], W_OK))
        printf("-");
    else
        printf("w");
    if (access(argv[1], X_OK))
        printf("-");
    else
        printf("x");
    printf("\n");
    return 0;
}