#include "minishell.h"

void shell_loop(void)
{
	char	*cl;
	size_t	cn;

	cl = getcl();
	while (cl)
	{
		add_history(cl);
		cl = envcl(cl);
		if (!cl)
			break;
		cl = asterisk(cl);
		if (!cl)
			break;
		exe_line(cl);
		free(cl);
		cl = getcl();
	}
	return ;
}
