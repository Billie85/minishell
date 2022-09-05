#include "minishell.h"
//#include "debug.h"

void	*m_error(void)
{
	printf("malloc error\n");
	return (NULL);
}

char	**cpy_list(char	**p)
{
	return (cpy_list_std(p, 0));
}

char	**cpy_list_std(char	**p, size_t dw)
{
	char	*s;
	char	**r;

	if (!(*p))
	{
		r = malloc((dw + 1) * sizeof(char **));
		if (!r)
			return (m_error());
		r[dw] = NULL;
		return (r);
	}
	s = strdup(*p);
	if (!s)
		return (m_error());
	r = cpy_list_std(p + 1, dw + 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	r[dw] = s;
	return (r);
}

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
