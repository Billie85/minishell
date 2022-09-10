#include "../minishell_bonus.h"
#include "getcl_bonus.h"

extern t_g	g_;

char	*getcl(void)
{
	char			*cl;
	char			*r;
	struct termios	s;

	tcgetattr(STDIN_FILENO, &s);
	s.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
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
	s.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	return (r);
}
