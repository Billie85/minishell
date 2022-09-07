/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_getcl_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:21:19 by blyu              #+#    #+#             */
/*   Updated: 2022/09/06 18:21:20 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "getcl.h"

extern t_g	g_;

char	*getcl(void)
{
	char	*cl;
	char	*r;

	g_.status = READING;
	cl = readline(PROMPT);
	if (!cl)
	{
		g_.status = EXEING;
		return (NULL);
	}
	r = gcl_std(cl, 0);
	free(cl);
	g_.status = EXEING;
	return (r);
}
