#include "minishell2.h"
//#include "debug.h"

int	g_;
int	exeret = 0;

void	preexe(char **envp)
{
	struct termios	s;

	envp = cpy_list(envp);
	for (size_t i = 0; envp[i]; i++)
	{
		printf("%zu\t:%s\n", i, envp[i]);
	}
	if (!envp)
		exit(1);
	ev(envp);
	tcgetattr(STDIN_FILENO, &s);
	s.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	signal(SIGINT, sigint_handler);
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	preexe(envp);
	if (argc == 1)
		shell_loop();
	free_list(ev(NULL));
	return (0);
}