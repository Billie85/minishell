/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:07:44 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:07:45 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_g	g_;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_.status == READING)
	{
		printf ("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	sigquit_handler(int sig)
{
	(void)sig;
	if (g_.status == READING)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}
