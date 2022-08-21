//tell the update routines that we have moved onto a new line
//通常、改行を出力した後、新しい (空の) 行に移動したことを更新ルーチンに伝えます。

#include <stdio.h>

#include <readline/readline.h>
#include <signal.h>

int main(void) {
	
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}