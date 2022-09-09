
#include "minishell.h"
#include "debug.h"

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
	if (ft_strcmp(c->cmd[0], "exit"))
		return (0);
	if (c->cmd[1])
	{
		if (is_numustr(c->cmd[1]))
		{
			g_.retn = 255;
			ep3("minishell: exit: ", c->cmd[1], ": numeric argument required\n");
		}
		else
		{
			if (list_len(c->cmd) > 2)
				return (ep3("minishell: exit: too many arguments\n", "", "") * 0);
			g_.retn = ft_atoi(c->cmd[1]) & 0xff;
		}
	}
	else 
		g_.retn = g_.exeret & 0xff;
	printf("exit\n");
	return (1);
}
