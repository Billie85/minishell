#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (access("main.c", (R_OK | X_OK)))
	{
		perror("access");
		return -1;
	}
	printf("PASS\n");
	return 0;
}