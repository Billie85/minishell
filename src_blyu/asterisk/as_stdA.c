
#include "../minishell.h"
#include "asterisk.h"

size_t	as_std_aslen(char *cl);
char	*as_std1(char *cl, size_t B, size_t	i);
char	*as_std2(char *cl, size_t B, size_t	i);
char	*as_std3(char *cl, size_t B);
void	as_std3_cpy(char *r, size_t B, char **l);

char	*as_std(char *cl, size_t B)
{
	size_t	i;

	i = as_std_aslen(cl);
	if (!cl[i])
		return (as_std1(cl, B, i));
	else if (cl[i] == ' ')
		return (as_std2(cl, B, i));
	else
		return (as_std3(cl, B));
	return (NULL);
}

char	*as_std1(char *cl, size_t B, size_t	i)
{
	char	*r;

	r = malloc(B + i + 1);
	if (!r)
		return (m_error());
	r[B + i] = '\0';
	ft_memcpy(r + B, cl, i);
	return (r);
}

char	*as_std2(char *cl, size_t B, size_t	i)
{
	char	*r;

	while (cl[i] == ' ')
		i++;
	r = as_std(cl + i, B + i);
	if (!r)
		return (NULL);
	ft_memcpy(r + B, cl, i);
	return (r);
}

char	*as_std3(char *cl, size_t B)
{
	char	*r;
	char	**s;
	char	**l;
	size_t	i;
	size_t	ii;

	s = as_as_list(cl, 0);
	if (!s)
		return (NULL);
	l = find(s);
	free_list(s);
	if (!l)
		return (NULL);
	i = 0;
	ii = 0;
	while (l[i])
	{
		ii += ft_strlen(l[i]) + 3;
		i++;
	}
	r = as_std(skip_tk(cl), B + ii);
	if (!r)
		return (free_list_return(l, NULL));
	as_std3_cpy(r, B, l);
	return (r);
}

void	as_std3_cpy(char *r, size_t B, char **l)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	while (l[i])
	{
		r[B + ii] = '\'';
		ii++;
		ft_memcpy(r + B + ii, l[i], ft_strlen(l[i]));
		ii += ft_strlen(l[i]);
		ft_memcpy(r + B + ii, "\' ", 2);
		ii += 2;
		i++;
	}
	free_list(l);
}
