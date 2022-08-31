#include "minishell.h"
#include "debug.h"
extern int exeret;
int	exe_cmd(t_cmd *c);

void	cleanc(t_cmd	*c);

int exe_line(char *cl)
{
	t_cmd	c;
	int		i;

	while (*cl && *cl == ' ')
		cl++;
	c.cmd = NULL;
	c.n_type = CONTINUE;
	c.pipe[R_PIPE] = -1;
	c.pipe[W_PIPE] = -1;
	c.pipe[NEXT_PIPE] = -1;
	c.ps = 0;
	while (*cl)
	{
		c.pipe[R_PIPE] = c.pipe[NEXT_PIPE];
		c.pipe[NEXT_PIPE] = -1;
		cl = mkcmd(&c, cl);
//for (size_t i = 0; c.cmd[i]; i++)
//{
//TESTs(c.cmd[i])
//}
//TESTn(c.pipe[R_PIPE])
//TESTn(c.pipe[W_PIPE])
//TESTn(c.pipe[NEXT_PIPE])
//TESTn(c.n_type)
		i = exe_cmd(&c);
		cleanc(&c);
		if (i)
			return (1);
		while (*cl && *cl == ' ')/* 不要 */
			cl++;
	}
	return (0);
}

void	cleanc(t_cmd	*c)
{
	size_t	i;

	i = 0;
	if (c->cmd)
	{
		while (c->cmd[i])
		{
			free(c->cmd[i]);
			i++;
		}
		free(c->cmd);
	}
	c->cmd = NULL;
	if (c->pipe[R_PIPE] >= 0)
		close(c->pipe[R_PIPE]);
	if (c->pipe[W_PIPE] >= 0)
		close(c->pipe[W_PIPE]);
	c->pipe[R_PIPE] = -1;
	c->pipe[W_PIPE] = -1;
	return ;
}