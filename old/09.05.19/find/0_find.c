#include "../minishell.h"
#include "find.h"

#include "../debug.h"

char	**find(char **lst)
{
	char	**l;
	size_t	i;
	size_t	ii;

	l = fi_list(lst[0]);
	if (!l)
		return (NULL);
	i = 0;
	ii = 0;
	while (l[i])
	{
		if (fi_ok(l[i], lst))
		{
			l[ii] = l[i];
			ii++;
		}
		else
			free(l[i]);
		i++;
	}
	l[ii] = NULL;
	return (l);
}

/* 
int main(int argc, char *argv[]) {

	if (argc <= 1)
		return (0);
	for (size_t i = 1; argv[i]; i++)
	{
		printf("%zu\t:%s[\\n]\n", i, argv[i]);
	}
//TEST_
	char	**t = find(argv + 1);	
	for (size_t i = 0; t[i]; i++)
	{
		printf("%zu\t:%s[\\n]\n", i, t[i]);
	}
	return 0;
}
 */