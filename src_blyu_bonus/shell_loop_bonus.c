#include "minishell_bonus.h"

void	shell_loop(void)
{
	char	*cl;
	int		i;

	cl = getcl();
	while (cl)
	{
		add_history(cl);
		cl = envcl(cl);
		if (!cl)
			break ;
		cl = asterisk(cl);
		if (!cl)
			break ;
		i = exe_line(cl);
		free(cl);
		if (i)
			break ;
		cl = getcl();
	}
	return ;
}
