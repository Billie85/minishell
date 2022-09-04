#include "../minishell.h"
#include "getcl.h"

#include "../debug.h"

char	*gcl_std(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (!((!i || cl[i - 1] != '\\') && cl[i] == '\\' && cl[i + 1] == '\0') \
	&& cl[i] != '"' \
	&& cl[i] != '\'' \
	&& cl[i] != '|' && strncmp(cl + i, "&&", 2)/*  */ \
		&& cl[i])
		i++;
	if (!cl[i])
	{
//TEST
		r = malloc(B + i + 1);
		if (!r)
			return(m_error());
		r[B + i] = '\0';
	}
	else if (cl[i] == '|' || cl[i] == '&')
	{
//TEST
		r = gcl_nc(cl + i, B + i);
		if (!r)
			return (NULL);
	}
	else if (cl[i] == '\\')
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_std(ncl, B + i);
			free(ncl);
			if (!r)
				return (NULL);
		}
	}
	else if (cl[i] == '"')
	{
//TEST
		r = gcl_dq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	else //(cl[i] == '\'')
	{
//TEST
		r = gcl_sq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25
