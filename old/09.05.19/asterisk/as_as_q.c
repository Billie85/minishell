#include "../minishell.h"
#include "asterisk.h"

#include "../debug.h"

char	*as_as_q(char *cl, char **cln, size_t B, char c)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != c)
		i++;
	r = as_as_std(cl + i + 1, cln, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
