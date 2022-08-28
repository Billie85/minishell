#include "minishell.h"
	int exeret = 0;

int exe_line(char *cl)
{
	int pipe[3];
	t_cmd c;

	while (*cl || *cl == ' ')
		cl++;
	pipe[R_PIPE] = -1;
	pipe[W_PIPE] = -1;
	pipe[NEXT_PIPE] = -1;
	while (*cl)
	{
		pipe[R_PIPE] = pipe[NEXT_PIPE];
		pipe[NEXT_PIPE] = -1;
		cl = mkcmd(&c, cl, pipe);
		exeret = exe_cmd(&c);
		closefd(pipe);
		while (*cl || *cl == ' ')
			cl++;
	}
	return (0);
}