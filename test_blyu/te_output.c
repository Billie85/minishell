#include<stdio.h>
#include<fcntl.h>	
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[])
{
	if (argc != 3)
		return 0;
	write(1,"start\n",7);
	int fd; 
	fd = open(argv[1], O_WRONLY);
	printf("fd = %d", fd);
	write(fd, argv[2], strlen(argv[2]));
	close(fd);
	return 0;
}
