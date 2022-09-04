#include "minishell.h"
#include "debug.h"

int	g_;
int	exeret = 0;
void	preexe(char **envp);

int	main(int argc, char *argv[], char *envp[])
{
	preexe(envp);
//TEST
	if (argc == 1)
		shell_loop();
	free_list(ev(NULL));
	return (0);
}

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
	s.c_lflag &= ~(ECHOCTL);//ECHOCTILが定義されていません。
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	signal(SIGINT, sigint_handler);
	//signal(SIGQUIT, sigint_handler);
	return ;
}
