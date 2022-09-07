
#include "minishell.h"

extern t_g	g_;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_.status & SIGCOME)
		g_.status &= ~SIGCOME;
	else if (g_.status == EXEING)
	{
		g_.status |= SIGCOME;
		kill(0, SIGINT);
		printf("^C\n");
	}
	else
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
	if (g_.status & SIGCOME)
		g_.status &= ~SIGCOME;
	else if (g_.status == EXEING)
	{
		g_.status |= SIGCOME;
		kill(0, SIGQUIT);
		printf("^\\\n");
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}
