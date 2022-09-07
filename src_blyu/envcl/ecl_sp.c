
#include "../minishell.h"
#include "envcl.h"

char	*ecl_sp1(char *cl, size_t B);
char	*ecl_sp2(char *cl, size_t B);
char	*ecl_sp3(char *cl, size_t B);

char	*ecl_sp(char *cl, size_t B)
{
	if (*cl == ' ')
		return (ecl_sp1(cl, B));
	else if (!ft_strncmp(cl, ">>", 2) || !ft_strncmp(cl, "<<", 2) \
	|| !ft_strncmp(cl, "||", 2) || !ft_strncmp(cl, "&&", 2))
		return (ecl_sp2(cl, B));
	else
		return (ecl_sp3(cl, B));
	return (NULL);
}

char	*ecl_sp1(char *cl, size_t B)
{
	char	*r;

	while (*cl == ' ' && *cl)
		cl++;
	r = ecl_std(cl, B);
	return (r);
}

char	*ecl_sp2(char *cl, size_t B)
{
	char	*r;
	size_t	i;

	i = 2;
	r = ecl_std(cl + i, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = ' ';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*ecl_sp3(char *cl, size_t B)
{
	char	*r;
	size_t	i;

	i = 1;
	r = ecl_std(cl + i, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = ' ';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
