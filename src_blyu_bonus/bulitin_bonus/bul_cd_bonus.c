#include "../minishell_bonus.h"

int	bul_cd(int argc, char *argv[])
{
	char	pathname[PATHNAME_SIZE];

	if (argc == 2)
	{
		if (access(argv[1], F_OK))
		{
			ft_putstr_fd("the file not exit\n", 2);
			return (1);
		}
		if (access(argv[1], X_OK))
			return (ep3("cd: permission denied: ", argv[1], "\n"));
		if (chdir(argv[1]))
			return (ep3("cd: not a directory: ", argv[1], "\n"));
		getcwd(pathname, PATHNAME_SIZE);
		return (set_env("PWD", pathname));
	}
	else
	{
		ft_putstr_fd("invalid args\n", 2);
		return (1);
	}
}
