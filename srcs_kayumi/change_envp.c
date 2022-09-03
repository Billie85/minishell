#include "minishell2.h"

t_envp	*new_lstnew(char *name_envp, char *after_equal)
{
	t_envp	*lst;

	lst = (t_envp *)malloc(sizeof(t_envp));
	lst->next = NULL;
	lst->content = after_equal;
	lst->name = name_envp;
	return (lst);
}

void	make_envp_list(char *envp[], t_envp *envp_lst)
{
	int	i;
	int	name;
	int	after_equal;

	i = 0;
	name = 0;
	while(envp[i])
	{
		while(envp[i][name] != '=')
		name++;//イコールまでの部分が表示される。
		envp_lst->name = ft_substr(envp[i], 0, name);
		while(envp[i][after_equal] != '\0')
		after_equal++;//イコール以降が出力される。
		envp_lst->content = ft_substr(envp[i], name + 1, after_equal);
		envp_lst->next = new_lstnew(NULL, NULL);
		envp_lst = envp_lst->next;
		i++;
	}
}

t_envp	*change_envp(char *envp[])
{
	t_envp	*lst_envp;
	t_envp	*lst_tmp;

	lst_envp = new_lstnew(NULL,NULL);
	lst_tmp = lst_envp;
	make_envp_list(envp, lst_envp);
	return (lst_tmp);
}