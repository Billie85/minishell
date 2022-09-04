#include "minishell2.h"
//#include "debug.h"

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
