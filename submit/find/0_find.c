#include "../minishell.h"
#include "find.h"

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
