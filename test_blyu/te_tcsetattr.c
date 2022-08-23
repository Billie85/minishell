/* gcc te_tcsetattr.c */
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* 
int main(void)
{
    struct termios s;
    tcgetattr(STDIN_FILENO,&s);
    struct termios bs = s;
    s.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
    write(STDIN_FILENO, "input\t\t->", 10);
    char str[1024];
    bzero(str, 1024);
    read(STDIN_FILENO, str, 1024);
    printf("\nyour input\t->%s", str);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &bs);
    return 0;
}
 */

int main(void)
{
    struct termios s;
    tcgetattr(STDIN_FILENO,&s);
    struct termios bs = s;
    s.c_lflag &= ~(ICANON);
    s.c_cc[VMIN] = 1;
    s.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
    char c;
    while (1)
    {
        write(STDOUT_FILENO, "\n>", 3);
        read(STDIN_FILENO, &c, 1);
        write(STDOUT_FILENO, "\n)", 3);
        write(STDOUT_FILENO, &c, 2);

    }
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &bs);
    return 0;
}