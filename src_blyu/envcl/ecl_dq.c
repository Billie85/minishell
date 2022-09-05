#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_dq1(void);
char	*ecl_dq2(char	*cl, size_t	B, size_t i);
char	*ecl_dq3(char	*cl, size_t	B, size_t i);

char	*ecl_dq(char	*cl, size_t	B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '"' && cl[i] != '$' && cl[i])
		i++;
	if (!cl[i])//構文エラー
		return (ecl_dq1());
	else if (cl[i] == '$')
		return (ecl_dq2(cl, B, i));
	else //(cl[i] == '"')
		return (ecl_dq3(cl, B, i));
	return (NULL);
}

char	*ecl_dq1(void)
{
	printf("syntax error\n");
	return (strdup(""));/*  */
}

char	*ecl_dq2(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = ecl_env_dq(cl + i, B + i);
	if (!r || !*r)
		return (r);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_dq3(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = ecl_std(cl + i + 1, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = '"';
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
