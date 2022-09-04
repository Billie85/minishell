#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_std(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (cl[i] != ' ' && cl[i] != '<' && cl[i] != '>' && cl[i] != '|' && cl[i] != ';' && strncmp(cl + i, "&&", 2)/*  */ \
	&& cl[i] != '$' \
	&& cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' \
	&& cl[i])
		i++;
	if (!cl[i])
	{
		r = malloc(B + i + 1);
		if (!r)
			return(m_error());
		r[0] = (char)1;
		r[B + i] = '\0';
	}
	else if (cl[i] == ' ' || cl[i] == '<' || cl[i] == '>' || cl[i] == '|' || cl[i] == ';' || cl[i] == '&')
	{
		r = ecl_sp(cl + i, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = ' ';
	}
	else if (cl[i] == '$')
	{
		r = ecl_env_std(cl + i, B + i);
		if (!r || !*r)
			return (r);
	}
	else if (cl[i] == '\\')
	{
		i += 2;
		r = ecl_std(cl + i, B + i);
		if (!r || !*r)
			return (r);
	}
	else if (cl[i] == '"')
	{
		r = ecl_dq(cl + i + 1, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = '"';
	}
	else //(cl[i] == '\'')
	{
		r = ecl_sq(cl + i + 1, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25
