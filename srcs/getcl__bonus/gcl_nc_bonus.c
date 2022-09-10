#include "../minishell_bonus.h"
#include "getcl_bonus.h"

char	*gcl_nc1(char	*cl, size_t	B, size_t i);
char	*gcl_nc2(char	*cl, size_t	B, size_t i);

char	*gcl_nc(char	*cl, size_t	B)
{
	size_t	i;
	int		e;

	i = 0;
	e = 1;
	while ((cl[i] == '|' || cl[i] == '&') && i < 2)
		i++;
	while (cl[i] && (cl[i] == ' ' || cl[i] == '|' \
	|| !ft_strncmp(cl + i, "&&", 2)))
	{
		if (cl[i] == '|' || cl[i] == '&')
		{
			e = 0;
			while (cl[i])
				i++;
		}
		else
			i++;
	}
	if (!cl[i] && e)
		return (gcl_nc1(cl, B, i));
	else
		return (gcl_nc2(cl, B, i));
	return (NULL);
}

char	*gcl_nc1(char	*cl, size_t	B, size_t i)
{
	char	*ncl;
	char	*r;

	ncl = readline(PROMPT_);
	if (!ncl)
		r = gcl_std("", B + i);
	else
	{
		r = gcl_nc(ncl, B + i);
		free(ncl);
		if (!r)
			return (NULL);
	}
	ft_memcpy(r + B, cl, i);
	return (r);
}

char	*gcl_nc2(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = gcl_std(cl + i, B + i);
	if (!r)
		return (NULL);
	ft_memcpy(r + B, cl, i);
	return (r);
}
