#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_sq(char	*cl, size_t	B)
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	while (cl[i] != '\'' && cl[i])
		i++;
	if (!cl[i])
	{//構文エラー
		printf("syntax error\n");
		r = strdup("");
		return (r);
	}
	else //(cl[i] == '\'')
	{
		r = ecl_std(cl + i + 1, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
