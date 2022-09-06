#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_std1(char	*cl, size_t	B, size_t i);
char	*ecl_std2(char	*cl, size_t	B, size_t i);
char	*ecl_std3(char	*cl, size_t	B, size_t i);
char	*ecl_std4(char	*cl, size_t	B, size_t i);
char	*ecl_std5(char	*cl, size_t	B, size_t i);
char	*ecl_std6(char	*cl, size_t	B, size_t i);

char	*ecl_std(char	*cl, size_t	B)
{
	size_t	i;

	i = 0;
	while (cl[i] != ' ' && cl[i] != '<' && cl[i] != '>' && cl[i] != '|' && cl[i] != ';' && strncmp(cl + i, "&&", 2)/*  */ \
			&& cl[i] != '$' \
			&& cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' \
			&& cl[i])
		i++;
	if (!cl[i])
		return (ecl_std1(cl, B, i));
	else if (cl[i] == ' ' || cl[i] == '<' || cl[i] == '>' || cl[i] == '|' || cl[i] == ';' || cl[i] == '&')
		return (ecl_std2(cl, B, i));
	else if (cl[i] == '$')
		return (ecl_std3(cl, B, i));
	else if (cl[i] == '\\')
		return (ecl_std4(cl, B, i));
	else if (cl[i] == '"')
		return (ecl_std5(cl, B, i));
	else //(cl[i] == '\'')
		return (ecl_std6(cl, B, i));
	return (NULL);
}

char	*ecl_std1(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = malloc(B + i + 1);
	if (!r)
		return (m_error());
	r[0] = (char)1;
	r[B + i] = '\0';
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_std2(char *cl, size_t B, size_t i)
{
	char	*r;

	r = ecl_sp(cl + i, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = ' ';
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_std3(char *cl, size_t B, size_t i)
{
	char	*r;

	r = ecl_env_std(cl + i, B + i);
	if (!r || !*r)
		return (r);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_std4(char *cl, size_t B, size_t i)
{
	char	*r;

	i += 2;
	r = ecl_std(cl + i, B + i);
	if (!r || !*r)
		return (r);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
