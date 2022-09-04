#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "debug.h"

void	itosd1(char	*str, int n);

void	itosd(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	if (str < 0)
	{
		*str = '-';
		str++;
	}
	else
		n *= -1;
	itosd1(str, n);
	return ;
}

void	itosd1(char	*str, int n)
{
	int	nn;

	nn = 1;
	while (n / nn < -10)
		nn *= 10;
	while (nn > 0)
	{
		*str = '0' - (n / nn);
		n %= nn;
		str++;
		nn /= 10;
	}
	*str = '\0';
	return ;
}

void	free_list(char	**p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return ;
}
char	**cpy_list_std(char	**p, size_t dw);

char	**cpy_list(char	**p)
{
	return (cpy_list_std(p, 0));
}

char	**cpy_list_std(char	**p, size_t dw)
{
	char	*s;
	char	**r;

	if (!(*p))
	{
		r = malloc((dw + 1) * sizeof(char **));
		if (!r)
			return(m_error());
		r[dw] = NULL;
		return (r);
	}
	s = strdup(*p);
	if (!s)
		return(m_error());
	r = cpy_list_std(p + 1, dw + 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	r[dw] = s;
	return (r);
}
//25
//too manyu functions

size_t	list_len(char **l)//too many function in file
{
	size_t	i;

	if (!l)
		return (0);
	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	*m_error(void)
{
	printf("malloc error\n");
	return (NULL);
}

void	*free_return(void *p, void *r)
{
	if (!p)
		free(p);
	return (r);
}

void	*free_list_return(void *l, void *r)
{
	if (!l)
		free_list(l);
	return (r);
}