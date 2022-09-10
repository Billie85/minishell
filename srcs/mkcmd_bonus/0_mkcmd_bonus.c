/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_mkcmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:06 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:44:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

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
