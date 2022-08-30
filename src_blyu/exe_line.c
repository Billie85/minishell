#include "minishell.h"
extern int exeret;

int exe_line(char *cl)
{
	t_cmd c;

	while (*cl || *cl == ' ')
		cl++;
	c.n_type = CONTINUE;
	c.pipe[R_PIPE] = -1;
	c.pipe[W_PIPE] = -1;
	c.pipe[NEXT_PIPE] = -1;
	while (*cl)
	{
		c.pipe[R_PIPE] = c.pipe[NEXT_PIPE];
		c.pipe[NEXT_PIPE] = -1;
		cl = mkcmd(&c, cl);
		exeret = exe_cmd(&c);
		closefd(&c);
		while (*cl && *cl == ' ')/* 不要 */
			cl++;
	}
	return (0);
}