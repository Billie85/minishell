#include "../minishell.h"
#include "../debug.h"

int	bul_env(int argc, char *argv[])
{
	char	**env;

	env = ev(NULL);
	if (!env)
		return (1);
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
