/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_dq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:34 by blyu              #+#    #+#             */
/*   Updated: 2022/09/06 18:23:35 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "mkcmd.h"

char	*tk_dq(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '"' && ft_strncmp(cl + i, "$?", 2))
		i++;
	if (cl[i] == '$')
	{
		r = tk_ques(cl + i, B + i, tk_dq);
		if (!r)
			return (NULL);
	}
	else
	{
		r = tk_std(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
