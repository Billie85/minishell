#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "debug.h"

size_t	list_len(char **l)
{
	size_t	i;

	if (!l)
		return (0);
	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	free_list(char	**p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return ;
}

void	*free_return(void *p, void *r)
{
	if (!p)
		free(p);
	return (r);
}

void	*free_list_return(void *l, void *r)
{
	if (!l)
		free_list(l);
	return (r);
}
