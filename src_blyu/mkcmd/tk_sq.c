#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	*tk_sq(char *cl, size_t B)
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	while (cl[i] != '\'')
		i++;
	r = tk_std(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
