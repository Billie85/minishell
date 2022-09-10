/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcl_stdB_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:03:37 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:03:38 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "getcl_bonus.h"

char	*gcl_std5(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = gcl_sq(cl + i + 1, B + i + 1);
	if (!r)
		return (NULL);
	r[B + i] = '\'';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
