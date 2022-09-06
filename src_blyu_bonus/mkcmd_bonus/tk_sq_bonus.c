#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

char	*tk_sq(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '\'')
		i++;
	r = tk_std(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
