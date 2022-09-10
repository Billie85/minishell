#include "../minishell.h"
#include "getcl.h"

char	*gcl_std5(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = gcl_sq(cl + i + 1, B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = '\'';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
