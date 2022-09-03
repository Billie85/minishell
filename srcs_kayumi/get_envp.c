//先にenvpを使って環境変数をリストに格納する
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

void	new_lstadd_back(t_envp **envp, t_envp *new_str)
{
	t_envp	*tmp;

	tmp = *envp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_str;
}

int	get_envp(char *up_to_equal, char *envp[], char *after_equal)
{
	t_list	*head;
	t_envp	*head_envp;
	int		i;
	
	head = ft_lstnew(ft_strdup(envp[0]));
	i = 0;
	while (envp[i])
	{
		ft_lstadd_back(&head, ft_lstnew(envp[i]));
		new_lstadd_back(&head, new_lstnew(up_to_equal, after_equal));
		printf("%s\n", envp[i]);
		i++;
	}
}
//ft_strdupを使って複製する理由として後々unsetコマンド(変数や関数を削除する)を使う
