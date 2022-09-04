#include "minishell.h"
#include "debug.h"

extern int	exeret;

int	exe_cmd1(t_cmd *c);
void exe_start(t_cmd *c, char *cm);

int	exe_cmd(t_cmd *c)
{
	char	*cm;
	pid_t	i;
//TESTn(c->n_type)
	if(c->n_type == SYNTAXERROR)
		return (1);
	else if (c->n_type == SKIP)
		return (0);
 	if (isbulitin(c->cmd[0]))
		return(exe_bulitin(c));
	cm = cm_name(c->cmd[0]);
//TESTs(cm)
	if(!cm)
		return (1);
	else if (!*cm)
	{
		free(cm);
		return (0);
	}
	i = fork();
	if (i < 0)
	{
		printf("fork error \n");
		return (1);
	}
	if (i == 0)
		exe_start(c, cm);
	free(cm);
	return (exe_cmd1(c));
}

int	exe_cmd1(t_cmd *c)
{	
	c->ps++;
	while (c->n_type != PIPE && c->ps)
	{
		wait(&exeret);
		c->ps--;
	}
//TESTn(exeret)
	if (c->n_type == AND && exeret)
		c->n_type = SKIP;
	else if (c->n_type == OR && !exeret)
		c->n_type = SKIP;
	return (0);
}

void	exe_start(t_cmd *c, char *cm)
{
//TESTn(c->pipe[R_PIPE])
//TESTn(c->pipe[W_PIPE])
	if (c->pipe[NEXT_PIPE])
	close(c->pipe[NEXT_PIPE]);
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
	execve(cm, c->cmd, NULL);
	return ;
}
