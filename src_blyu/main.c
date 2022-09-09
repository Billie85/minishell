#include "minishell.h"

t_g	g_;

void	preexe(char **envp);

int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	preexe(envp);
	if (argc == 1)
		shell_loop();
	free_list(ev(NULL));
	return (g_.retn);
}

void	preexe(char **envp)
{
	struct termios	s;

	g_.exeret = 0;
	g_.status = EXEING;
	g_.retn = 0;
	envp = cpy_list(envp);
	if (!envp)
		exit(1);
	ev(envp);
	tcgetattr(STDIN_FILENO, &s);
	s.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	return ;
}
