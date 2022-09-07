/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_line_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:14:51 by root              #+#    #+#             */
/*   Updated: 2022/09/07 10:04:24 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_g	g_;

int		exe_cmd(t_cmd *c);
int		cleanc(t_cmd	*c);
void	initializec(t_cmd	*c);
int		is_exit(t_cmd	*c);

int	exe_line(char *cl)
{
	t_cmd	c;
	int		i;

	while (*cl && *cl == ' ')
		cl++;
	initializec(&c);
	while (*cl)
	{
		c.pipe[R_PIPE] = c.pipe[NEXT_PIPE];
		c.pipe[NEXT_PIPE] = -1;
		cl = mkcmd(&c, cl);
		if (c.n_type == SYNTAXERROR || !c.cmd[0])
			return (cleanc(&c));
		if (!cl || is_exit(&c))
			return (cleanc(&c) + 1);
		i = exe_cmd(&c);
		cleanc(&c);
		if (i)
			return (1);
		while (*cl && *cl == ' ')
			cl++;
	}
	return (0);
}

void	initializec(t_cmd	*c)
{
	c->cmd = NULL;
	c->n_type = CONTINUE;
	c->pipe[R_PIPE] = -1;
	c->pipe[W_PIPE] = -1;
	c->pipe[NEXT_PIPE] = -1;
	c->ps = 0;
	return ;
}

int	cleanc(t_cmd	*c)
{
	if (c->cmd)
		free_list(c->cmd);
	c->cmd = NULL;
	if (c->pipe[R_PIPE] >= 0)
		close(c->pipe[R_PIPE]);
	if (c->pipe[W_PIPE] >= 0)
		close(c->pipe[W_PIPE]);
	c->pipe[R_PIPE] = -1;
	c->pipe[W_PIPE] = -1;
	return (0);
}

int	is_exit(t_cmd *c)
{
	size_t	i;

	if (ft_strcmp(c->cmd[0], "exit"))
		return (0);
	printf("exit\n");
	if (c->cmd[1])
	{
		i = 0;
		while (c->cmd[1][i] && ft_isdigit(c->cmd[1][i]))
			i++;
		if (c->cmd[1][i])
		{
			g_.retn = 255;
			ep3("minishell: exit: ", c->cmd[1], ": numeric argument required\n");
		}
		else
			g_.retn = ft_atoi(c->cmd[1]) & 0xff;
	}
	return (1);
}
