#include "minishell.h"
#include "debug.h"

extern int	g_;

void	shell_loop(void)
{
	char	*cl;
	size_t	cn;
	int		i;

	g_ = READING;
	cl = getcl();
	g_ = EXEING;
	while (cl)
	{
		add_history(cl);
		cl = envcl(cl);
		if (!cl)
			break ;
		cl = asterisk(cl);
		if (!cl)
			break ;
//TESTs(cl)
		i = exe_line(cl);
		free(cl);
		if (i)
			break ;
		g_ = READING;
		cl = getcl();
		g_ = EXEING;
	}
	return ;
}//25
