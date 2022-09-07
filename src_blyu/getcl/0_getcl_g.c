
#include "../minishell.h"
#include "getcl.h"

extern t_g	g_;

char	*getcl(void)
{
	char	*cl;
	char	*r;

	g_.status = READING;
	cl = readline(PROMPT);
	if (!cl)
	{
		g_.status = EXEING;
		return (NULL);
	}
	r = gcl_std(cl, 0);
	free(cl);
	g_.status = EXEING;
	return (r);
}
