#include <unistd.h>
int main(void)
{
	write(STDOUT_FILENO, "hello world", 12);
	return 0;
}
