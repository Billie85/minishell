#include "minishell.h"

t_g	g_;

void	preexe(char **envp);

int	main(int argc, char *argv[], char *envp[])
{
	preexe(envp);
	if (argc == 1)
		shell_loop();
	free_list(ev(NULL));
	return (0);
}

void	preexe(char **envp)
{
	struct termios	s;

	g_.exeret = 0;
	g_.status = EXEING;
	envp = cpy_list(envp);
	if (!envp)
		exit(1);
	ev(envp);
	tcgetattr(STDIN_FILENO, &s);
	s.c_lflag &= ~(ECHOCTL);//ECHOCTILが定義されていません。
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	return ;
}
