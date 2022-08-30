#include "minishell.h"
#include "debug.h"

int g_;
int exeret = 0;

/* 
utils.c
zzz_libft.c
cc test_main.c envcl.c getcl.c mkcmd.c sig.c tool.c utils.c zzz_libft.c -lreadline
 */

int exe_line(char *cl)
{
	t_cmd c;

	while (!*cl || *cl == ' ')
		cl++;
	c.n_type = CONTINUE;
	c.pipe[R_PIPE] = -1;
	c.pipe[W_PIPE] = -1;
	c.pipe[NEXT_PIPE] = -1;
	while (*cl)
	{
TESTs(cl)
		c.pipe[R_PIPE] = c.pipe[NEXT_PIPE];
		c.pipe[NEXT_PIPE] = -1;
		cl = mkcmd(&c, cl);
		TEST_
		for (size_t i = 0; c.cmd[i]; i++)
		{
			TESTs(c.cmd[i])
		}
		TESTn(c.pipe[R_PIPE])
		TESTn(c.pipe[W_PIPE])
		TESTn(c.pipe[NEXT_PIPE])
		TESTn(c.n_type)
		if (c.pipe[R_PIPE])
			close(c.pipe[R_PIPE]);
		c.pipe[R_PIPE] = -1;
		if (c.pipe[W_PIPE])
			close(c.pipe[W_PIPE]);
		c.pipe[W_PIPE] = -1;
		while (*cl && *cl == ' ')
			cl++;
	}
	return (0);
}

int main(void)
{
	char *cl;
	t_cmd    *cmd;
	
	signal(SIGINT, sigint_handler);
	cl = getcl();
	while (cl)
	{
		add_history(cl);
		cl = envcl(cl);
		if (!cl)
			break;
		exe_line(cl);
		free(cl);
		cl = getcl();
	}
	return 0;
}
