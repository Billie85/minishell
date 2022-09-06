#include "../minishell.h"
#include "../debug.h"

int	bul_pwd(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	printf("%s\n", get_env("PWD"));
	return (0);
}
