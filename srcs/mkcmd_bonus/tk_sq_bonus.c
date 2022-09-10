/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_sq_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:43 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:44:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

char	*tk_sq(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '\'')
		i++;
	r = tk_std(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
