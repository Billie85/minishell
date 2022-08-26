#include "minishell.h"

void shell_loop(void)
{
	char	*cl;
	t_cmd	*cmd;
	size_t	cn;

	cl = getcl();
	while (cl)
	{
		add_history(cl);
		cmd = cmds(cl);
		if (!cmd)
		{
			free(cl);
			return ;
		}
		else if (cmd[0].n_type != NOCMD)
		{
			if (divide_cl(cmd, cl))
			{
				free_cmds(cmd);
				free(cl);
				return ;
			}
			exe_line(cmd);
		}
		free_cmds(cmd);
		free(cl);
		cl = getcl();
	}
	return ;
}
