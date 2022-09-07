/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:19:03 by blyu              #+#    #+#             */
/*   Updated: 2022/09/07 00:21:58 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envcl.h"

char	*extractenv(char *cl)
{
	size_t	i;
	char	*r;

	i = 0;
	cl++;
	while (cl[i] && (ft_isalnum(cl[i]) || cl[i] == '_'))
		i++;
	r = malloc(i + 1);
	if (!r)
		return (m_error());
	if (i)
		ft_memcpy(r, cl, i);
	r[i] = '\0';
	return (r);
}
