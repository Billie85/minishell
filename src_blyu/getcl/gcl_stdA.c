
#include "../minishell.h"
#include "getcl.h"

char	*gcl_std1(char	*cl, size_t	B, size_t i);
char	*gcl_std2(char	*cl, size_t	B, size_t i);
char	*gcl_std3(char	*cl, size_t	B, size_t i);
char	*gcl_std4(char	*cl, size_t	B, size_t i);
char	*gcl_std5(char	*cl, size_t	B, size_t i);

char	*gcl_std(char	*cl, size_t	B)
{
	size_t	i;

	i = 0;
	while (!((!i || cl[i - 1] != '\\') && cl[i] == '\\' && cl[i + 1] == '\0') \
	&& cl[i] != '"' \
	&& cl[i] != '\'' \
	&& cl[i] != '|' && ft_strncmp(cl + i, "&&", 2) \
	&& cl[i])
		i++;
	if (!cl[i])
		return (gcl_std1(cl, B, i));
	else if (cl[i] == '|' || cl[i] == '&')
		return (gcl_std2(cl, B, i));
	else if (cl[i] == '\\')
		return (gcl_std3(cl, B, i));
	else if (cl[i] == '"')
		return (gcl_std4(cl, B, i));
	else
		return (gcl_std5(cl, B, i));
}

char	*gcl_std1(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = malloc(B + i + 1);
	if (!r)
		return (m_error());
	r[B + i] = '\0';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*gcl_std2(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = gcl_nc(cl + i, B + i);
	if (!r)
		return (NULL);
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*gcl_std3(char	*cl, size_t	B, size_t i)
{
	char	*r;
	char	*ncl;

	ncl = readline(PROMPT_);
	if (!ncl)
		r = gcl_std("", B + i);
	else
	{
		r = gcl_std(ncl, B + i);
		free(ncl);
		if (!r)
			return (NULL);
	}
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*gcl_std4(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = gcl_dq(cl + i + 1, B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = '"';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
