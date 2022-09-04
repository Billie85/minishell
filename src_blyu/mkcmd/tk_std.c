#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	*tk_std(char *cl, size_t B)
{
	size_t	i;
	char	*r;

//TESTs(cl)
	i = 0;
	while (cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' && strncmp(cl + i, "$?", 2) && cl[i] != ' ' && cl[i])
		i++;
	if (!cl[i] || cl[i] == ' ')
	{
//TESTn(B + i)
		r = malloc(B + i + 1);
		if (!r)
			return(m_error());
		r[0] = (char)1;
		r[B + i] = '\0';
	}
	else if (cl[i] == '$')
	{
//TEST
		r = tk_ques(cl + i, B + i, tk_std);
		if (!r)
			return (NULL);
	}
	else if (cl[i] == '\\')
	{
//TEST
		r = tk_std(cl + i + 2, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = cl[i + 1];
	}
	else if (cl[i] == '"')
	{
//TEST
		r = tk_dq(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	else //(cl[i] == '\'')
	{
//TEST
		r = tk_sq(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25
