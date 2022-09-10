/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_envcl_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:00:37 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:00:38 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "envcl_bonus.h"

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
