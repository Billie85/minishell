/* 
open(s, O_RDONLY, O_CREAT, S_IREAD | S_IWRITE);
 */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY | O_CREAT, S_IREAD | S_IWRITE);
    printf("%d\n", fd);
    pause();
    return (0);
}