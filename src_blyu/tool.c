#include <unistd.h>
#include <stdlib.h>
#include "debug.h"
void	itosd1(char	*str, int	n);

void	itosd(char	*str, int	n)
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

void	itosd1(char	*str, int	n)
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