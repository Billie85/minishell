/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_find_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:01:56 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:01:57 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "find_bonus.h"

char	**find(char **lst)
{
	char	**l;
	size_t	i;
	size_t	ii;

	l = fi_list(lst[0]);
	if (!l)
		return (NULL);
	i = 0;
	ii = 0;
	while (l[i])
	{
		if (fi_ok(l[i], lst))
		{
			l[ii] = l[i];
			ii++;
		}
		else
			free(l[i]);
		i++;
	}
	l[ii] = NULL;
	return (l);
}
