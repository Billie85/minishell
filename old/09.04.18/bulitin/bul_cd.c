#include "../minishell.h"
#include "../debug.h"

//fd=2
int bul_cd(int argc, char *argv[])
{
	char pathname[PATHNAME_SIZE];

	if (argc == 2)
	{
		if (access(argv[1], F_OK))
		{
			printf("the file not exit\n");
			return (1);
		}
		if (access(argv[1], X_OK))
		{
			printf("cd: permission denied: %s\n", argv[1]);
			return (1);
		}
		if (chdir(argv[1]))
		{

			printf("cd: not a directory: %s\n", argv[1]);
			return (1);
		}
		getcwd(pathname, PATHNAME_SIZE);
		return(set_env("PWD", pathname));	
	}
	else
	{
		printf("invalid args\n");
		return (0);
	}
}