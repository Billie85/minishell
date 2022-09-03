#include "minishell2.h"

int	info_builtin(t_envp *envp, char **args)
{
	if (ft_strcmp("echo", args[0]) == 0)
		return (0);
	else if(ft_strcmp("cd", args[0]) == 0)
		return (0);
	else if(ft_strcmp("pwd", args[0]) == 0)
		return (0);
	else if(ft_strcmp("export", args[0]) == 0)
		return (0);
	else if(ft_strcmp("unset", args[0]) == 0)
		return (export(envp));
	else if(ft_strcmp("env", args[0]) == 0)
		return (0);
	else if(ft_strcmp("exit", args[0]) == 0)
		return (0);
}