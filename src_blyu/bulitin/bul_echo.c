#include "../minishell.h"
#include "../debug.h"

int bul_echo(int argc, char *argv[])
{
	size_t	i;
	int	    nop;

	if (argc == 1)
        return (printf("\n") * 0);
    i = 1;
    nop = 0;
	while(!strcmp(argv[i], "-n"))/*  */
    {
        nop = 1;
		i++;
    }
	while(i < argc)
	{
		printf("%s", argv[i]);
		i++;
        if (i < argc)
        printf(" ");
	}
    if (!nop)
	    printf("\n");
	return (0);
}