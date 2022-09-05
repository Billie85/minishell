#include "../minishell.h"
#include "getcl.h"

#include "../debug.h"

char	*gcl_dq1(char	*cl, size_t	B, size_t i);
char	*gcl_dq2(char	*cl, size_t	B, size_t i);

char	*gcl_dq(char	*cl, size_t	B)
{
	size_t	i;

	i = 0;
	while (cl[i] != '"' && cl[i])
		i++;
	if (!cl[i])
		return (gcl_dq1(cl, B, i));
	else //(cl[i] == '"')
		return (gcl_dq2(cl, B, i));
	return (NULL);
}//25

char	*gcl_dq1(char	*cl, size_t	B, size_t i)
{
	char	*ncl;
	char	*r;

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
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*gcl_dq2(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = gcl_std(cl + i + 1, B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = '"';
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
