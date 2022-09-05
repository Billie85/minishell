#include "../minishell.h"
#include "asterisk.h"

#include "../debug.h"

char	*as_as_std1(char *cl, char **cln, size_t B, size_t	i);
char	*as_as_std2(char *cl, char **cln, size_t B, size_t	i);
char	*as_as_std3(char *cl, char **cln, size_t B, size_t	i);

char	*as_as_std(char *cl, char **cln, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] && cl[i] != '*' && cl[i] != ' ' && cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'')//line long
		i++;
	if (!cl[i] || cl[i] == '*' || cl[i] == ' ')
		return (as_as_std1(cl, cln, B, i));
	else if (cl[i] == '\\')
		return (as_as_std2(cl, cln, B, i));	
	else //	(cl[i] == '"' && cl[i] == '\'')
		return (as_as_std3(cl, cln, B, i));	
}

char	*as_as_std1(char *cl, char **cln, size_t B, size_t	i)
{
	char	*r;

	*cln = cl + i;
	r = malloc(B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = '\0';
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*as_as_std2(char *cl, char **cln, size_t B, size_t	i)
{
	char	*r;

	r = as_as_std(cl + i + 2, cln, B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = cl[i + 1];
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*as_as_std3(char *cl, char **cln, size_t B, size_t	i)
{
	char	*r;

	r = as_as_q(cl + i + 1, cln, B + i, cl[i]);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
