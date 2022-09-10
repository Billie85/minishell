/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecl_sq_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:01:00 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:01:01 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "envcl_bonus.h"

char	*ecl_sq(char	*cl, size_t	B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '\'' && cl[i])
		i++;
	if (!cl[i])
	{
		printf("syntax error\n");
		r = ft_strdup("");
		return (r);
	}
	else
	{
		r = ecl_std(cl + i + 1, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = '\'';
	}
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
