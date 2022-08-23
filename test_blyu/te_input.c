#include<stdio.h>
#include<fcntl.h>	
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[])
{
	if (argc != 3)
		return 0;
	int fdr, fdw; 
	fdr = open(argv[1], O_RDONLY);
	fdw = open(argv[2], O_WRONLY);
	printf("fdw = %d\nfdr = %d\n", fdr, fdw);
	char c;
	while (1)
	{
		read(fdr, &c, 1);
		write(fdw, &c, 1);
	}
	close(fdr);
	close(fdw);
	return 0;
}
