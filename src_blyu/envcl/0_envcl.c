/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_envcl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:18:20 by blyu              #+#    #+#             */
/*   Updated: 2022/09/06 18:18:21 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envcl.h"

char	*envcl(char *cl)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] == ' ' && cl[i])
		i++;
	r = ecl_std(cl + i, 0);
	free(cl);
	return (r);
}
