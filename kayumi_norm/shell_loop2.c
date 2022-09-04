#include "minishell2.h"
//#include "debug.h"

extern int	g_;

void	shell_loop(void)
{
	char	*cl;
	size_t	cn;
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
