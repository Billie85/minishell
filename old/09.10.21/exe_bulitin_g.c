#include "minishell.h"

extern t_g	g_;
void	exe_bulitin1(t_cmd *c);
void	exe_bulitin2(t_cmd *c);
void	exe_bulitin3(t_cmd *c);

int	isbulitin(char *s)
{
	return (!ft_strcmp(s, "echo") || !ft_strcmp(s, "cd") \
	|| !ft_strcmp(s, "pwd") || !ft_strcmp(s, "export") \
	|| !ft_strcmp(s, "unset") || !ft_strcmp(s, "env") || !ft_strcmp(s, "exit"));
}

int	exe_bulitin(t_cmd *c)
{
	exe_bulitin1(c);
	exe_bulitin2(c);
	exe_bulitin3(c);
	return (0);
}

void	exe_bulitin1(t_cmd *c)
{
	int		fd_buf;

	if (c->pipe[R_PIPE] >= 0)
	{
		fd_buf = dup(STDIN_FILENO);
		dup2(c->pipe[R_PIPE], STDIN_FILENO);
		close(c->pipe[R_PIPE]);
		c->pipe[R_PIPE] = fd_buf;
	}
	if (c->pipe[W_PIPE] >= 0)
	{
		fd_buf = dup(STDOUT_FILENO);
		dup2(c->pipe[W_PIPE], STDOUT_FILENO);
		close(c->pipe[W_PIPE]);
		c->pipe[W_PIPE] = fd_buf;
	}
	return ;
}

void	exe_bulitin2(t_cmd *c)
{
	int	i;

	i = list_len(c->cmd);
	if (!ft_strcmp(c->cmd[0], "echo"))
		g_.exeret = bul_echo(i, c->cmd);
	else if (!ft_strcmp(c->cmd[0], "cd"))
		g_.exeret = bul_cd(i, c->cmd);
	else if (!ft_strcmp(c->cmd[0], "pwd"))
		g_.exeret = bul_pwd(i, c->cmd);
	else if (!ft_strcmp(c->cmd[0], "export"))
		g_.exeret = bul_export(i, c->cmd);
	else if (!ft_strcmp(c->cmd[0], "unset"))
		g_.exeret = bul_unset(i, c->cmd);
	else if (!ft_strcmp(c->cmd[0], "env"))
		g_.exeret = bul_env(i, c->cmd);
	else
		g_.exeret = 1;
	return ;
}

void	exe_bulitin3(t_cmd *c)
{
	if (c->pipe[R_PIPE] >= 0)
	{
		dup2(c->pipe[R_PIPE], STDIN_FILENO);
		close(c->pipe[R_PIPE]);
	}
	if (c->pipe[W_PIPE] >= 0)
	{
		dup2(c->pipe[W_PIPE], STDOUT_FILENO);
		close(c->pipe[W_PIPE]);
	}
	if (c->n_type == AND && g_.exeret)
		c->n_type = SKIP;
	else if (c->n_type == OR && !(g_.exeret))
		c->n_type = SKIP;
	return ;
}
