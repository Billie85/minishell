#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	*tk_std1(char *cl, size_t B, size_t i);
char	*tk_std2(char *cl, size_t B, size_t i);
char	*tk_std3(char *cl, size_t B, size_t i);
char	*tk_std4(char *cl, size_t B, size_t i);
char	*tk_std5(char *cl, size_t B, size_t i);

char	*tk_std(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' && strncmp(cl + i, "$?", 2) && cl[i] != ' ' && cl[i])
		i++;
	if (!cl[i] || cl[i] == ' ')
		return (tk_std1(cl, B, i));
	else if (cl[i] == '$')
		return (tk_std2(cl, B, i));
	else if (cl[i] == '\\')
		return (tk_std3(cl, B, i));
	else if (cl[i] == '"')
		return (tk_std4(cl, B, i));
	else //(cl[i] == '\'')
		return (tk_std5(cl, B, i));
}

char	*tk_std1(char *cl, size_t B, size_t i)
{
	char	*r;

	r = malloc(B + i + 1);
	if (!r)
		return(m_error());
	r[0] = (char)1;
	r[B + i] = '\0';
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_std2(char *cl, size_t B, size_t i)
{
	char	*r;

	r = tk_ques(cl + i, B + i, tk_std);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_std3(char *cl, size_t B, size_t i)
{
	char	*r;

	r = tk_std(cl + i + 2, B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = cl[i + 1];
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_std4(char *cl, size_t B, size_t i)
{
	char	*r;

	r = tk_dq(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_std5(char *cl, size_t B, size_t i)
{
	char	*r;

	r = tk_sq(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
