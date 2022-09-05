#include "minishell.h"
//#include "debug.h"

extern int	g_;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_ & SIGCOME)
		g_ &= ~SIGCOME;
	else if (g_ == EXEING)
	{
		g_ |= SIGCOME;
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
	if (g_ & SIGCOME)
		g_ &= ~SIGCOME;
	else if (g_ == EXEING)
	{
		g_ |= SIGCOME;
		kill(0, SIGQUIT);
		printf("^\\\n");
	}
	return ;
}
