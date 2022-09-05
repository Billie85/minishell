#include "minishell.h"
//#include "debug.h"

extern int	exeret;

int	isbulitin(char *s)
{
	return (!strcmp(s, "echo") || !strcmp(s, "cd") || !strcmp(s, "pwd") || !strcmp(s, "export") || !strcmp(s, "unset") || !strcmp(s, "env") || !strcmp(s, "exit"));
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
}

void	exe_bulitin2(t_cmd *c)
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
}

int	exe_bulitin(t_cmd *c)
{
	int	i;

	exe_bulitin2(c);
	i = list_len(c->cmd);
	if (!strcmp(c->cmd[0], "echo"))
		exeret = bul_echo(i, c->cmd);
	else if (!strcmp(c->cmd[0], "cd"))
		exeret = bul_cd(i, c->cmd);
	else if (!strcmp(c->cmd[0], "pwd"))
		exeret = bul_pwd(i, c->cmd);
	else if (!strcmp(c->cmd[0], "export"))
		exeret = bul_export(i, c->cmd);
	else if (!strcmp(c->cmd[0], "unset"))
		exeret = bul_unset(i, c->cmd);
	else if (!strcmp(c->cmd[0], "env"))
		exeret = bul_env(i, c->cmd);
	exe_bulitin3(c);
	return (0);
}
