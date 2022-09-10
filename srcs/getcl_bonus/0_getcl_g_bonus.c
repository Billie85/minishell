/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_getcl_g_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:03:10 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:03:11 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "getcl_bonus.h"

extern t_g	g_;

char	*getcl(void)
{
	char			*cl;
	char			*r;
	struct termios	s;

	tcgetattr(STDIN_FILENO, &s);
	s.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
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
	s.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	return (r);
}
