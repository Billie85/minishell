#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_sp(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	if (*cl == ' ')
	{
		while (*cl == ' ' && *cl)
			cl++;
		r = ecl_std(cl, B);
		return (r);
	}
	else if (!strncmp(cl, ">>", 2) || !strncmp(cl, "<<", 2) || !strncmp(cl, "||", 2) || !strncmp(cl, "&&", 2))/*  */
	{
		i = 2;
		r = ecl_std(cl + i, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = ' ';
	}
	else //(*cl == '>' || *cl == '<' || *cl == '|' || *cl == ';')
	{
		i = 1;
		r = ecl_std(cl + i, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = ' ';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
