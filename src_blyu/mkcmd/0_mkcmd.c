/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_mkcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:06 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 18:30:34 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "mkcmd.h"

char	*mkcmd(t_cmd *c, char *cl)
{
	char	*ncl;

	c->cmd = cmdlist(c, cl, &ncl, 0);
	if (!(c->cmd) && c->n_type != SYNTAXERROR)
		return (NULL);
	if (c->n_type == SYNTAXERROR)
		ncl = cl + ft_strlen(cl);
	return (ncl);
}
