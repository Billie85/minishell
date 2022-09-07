/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:47 by root              #+#    #+#             */
/*   Updated: 2022/09/06 20:13:57 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	itosd1(char	*str, int n);
char	**cpy_list_std(char	**p, size_t dw);

void	itosd(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	if (n < 0)
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
			return (m_error());
		r[dw] = NULL;
		return (r);
	}
	s = ft_strdup(*p);
	if (!s)
		return (m_error());
	r = cpy_list_std(p + 1, dw + 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	r[dw] = s;
	return (r);
}

void	*m_error(void)
{
	printf("malloc error\n");
	return (NULL);
}
