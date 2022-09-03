#include "minishell2.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_envp *lst;
	lst = change_envp(envp);//ここでenvpを構造体に格納している。
	builtin_info(envp);		//ここでbuiltinコマンドの管理をしている。
	return (0);
}