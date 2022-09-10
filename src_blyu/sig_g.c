#include "minishell.h"

extern t_g	g_;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_.status == READING)
	{
		printf ("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	sigquit_handler(int sig)
{
	(void)sig;
	if (g_.status == READING)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}
