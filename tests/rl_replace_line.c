//replace the contents of rl_line_buffer with text
//rl_line_buffer の内容をテキストに置き換える

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
#include <signal.h>

int main(void)
{
	int sig;

	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		exit(1);
	}
	else if (sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
		exit(1);
	}
}