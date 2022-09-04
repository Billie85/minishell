#include "../minishell.h"
#include "getcl.h"

#include "../debug.h"

char	*gcl_dq(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (cl[i] != '"' && cl[i])
		i++;
	if (!cl[i])
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_dq(ncl, B + i + 1);
			free(ncl);
			if (!r)
				return (NULL);
			r[B + i] = '\n';
		}
	}
	else //(cl[i] == '"')
	{
		r = gcl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25
