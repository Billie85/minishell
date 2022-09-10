/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcl_stdB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:02:57 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:02:58 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "getcl.h"

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
