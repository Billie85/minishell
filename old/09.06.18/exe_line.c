#include "minishell.h"

int		exe_cmd(t_cmd *c);
void	cleanc(t_cmd	*c);
void	initializec(t_cmd	*c);

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
			return (0);
		if (!cl || !ft_strcmp(c.cmd[0], "exit"))
			return (1);
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

void	cleanc(t_cmd	*c)
{
	free_list(c->cmd);
	c->cmd = NULL;
	if (c->pipe[R_PIPE] >= 0)
		close(c->pipe[R_PIPE]);
	if (c->pipe[W_PIPE] >= 0)
		close(c->pipe[W_PIPE]);
	c->pipe[R_PIPE] = -1;
	c->pipe[W_PIPE] = -1;
	return ;
}
