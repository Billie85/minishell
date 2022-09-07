/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:20:21 by blyu              #+#    #+#             */
/*   Updated: 2022/09/06 18:20:22 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "find.h"

void	fi_dir(char **r)
{
	size_t	i;
	size_t	ii;
	size_t	l;

	i = 0;
	ii = 0;
	while (r[i])
	{
		l = ft_strlen(r[i]);
		if ((l >= 2 && r[i][l - 2] == '/' && r[i][l - 1] == '.') \
		|| (l == 1 && r[i][0] == '.'))
		{
			r[i][l - 2] = '\0';
			if (r[i + 1] && ! ft_strncmp (r[i + 1], r[i], ft_strlen(r[i])))
				free(r[i]);
			else
			{
				r[ii++] = r[i];
			}
		}
		else
			r[ii++] = r[i];
		i++;
	}
	r[ii] = NULL;
}
