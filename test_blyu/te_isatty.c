#include <unistd.h>
#include <fcntl.h>
#include "debug.h"

int main(int argc, char *argv[])
{
    TESTn(isatty(STDIN_FILENO))
    TESTn(isatty(STDOUT_FILENO))
    TESTn(isatty(STDERR_FILENO))
    TESTn(isatty(3))
    int fd = open(argv[1], O_RDONLY);
    TESTn(fd)
    TESTn(isatty(fd))
    close(fd);
    return 0;
}