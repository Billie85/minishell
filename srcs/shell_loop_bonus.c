/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:07:18 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:07:19 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	shell_loop(void)
{
	char	*cl;
	int		i;

	cl = getcl();
	while (cl)
	{
		if (*cl)
			add_history(cl);
		cl = envcl(cl);
		if (!cl)
			break ;
		cl = asterisk(cl);
		if (!cl)
			break ;
		i = exe_line(cl);
		free(cl);
		if (i)
			break ;
		cl = getcl();
	}
	return ;
}
