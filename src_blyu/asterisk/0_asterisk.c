#include "../minishell.h"
#include "asterisk.h"

#include "../debug.h"

char	*asterisk(char *cl)
{
	char	*r;

	r = as_std(cl, 0);
	free(cl);
	return (r);
}

/* 
int	main(int argc, char *argv[])
{
	char **s;
	TESTs(argv[1])
	s = as_as_list(argv[1], 0);
	for (size_t i = 0; s[i]; i++)
	{
		printf("%zu\t %s\n", i, s[i]);
	}
	return (0);
} */
