#include "../minishell.h"
#include "getcl.h"

#include "../debug.h"

char	*gcl_nc(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;
	int		e;

	i = 0;
	e = 1;
	while ((cl[i] == '|' || cl[i] == '&') && i < 2)
		i++;
	while (cl[i] && (cl[i] == ' ' || cl[i] == '|' || !strncmp(cl + i, "&&", 2)))
	{
		if (cl[i] == '|' || cl[i] == '&')
		{
			e = 0;
			while (cl[i])
				i++;
		}
		else
			i++;
	}
	if (!cl[i] && e)
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_nc(ncl, B + i);
			free(ncl);
			if (!r)
				return (NULL);
		}
	}
	else
	{
		r = gcl_std(cl + i, B + i);
		if (!r)
			return (NULL);
	}
	memcpy(r + B, cl, i);/*  */
	return (r);
}//25
