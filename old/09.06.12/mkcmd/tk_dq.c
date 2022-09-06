#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	*tk_dq(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '"' && strncmp(cl + i, "$?", 2))
		i++;
	if (cl[i] == '$')
	{
		r = tk_ques(cl + i, B + i, tk_dq);
		if (!r)
			return (NULL);
	}
	else //(cl[i] == '"')
	{
		r = tk_std(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
