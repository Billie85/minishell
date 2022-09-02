//先にenvpを使って環境変数をリストに格納する
#include "minishell2.h"


t_envp	*ft_lstnew(void *content);
char	*ft_strdup(const char *s);
t_envp	*ft_lstlast(t_envp *lst);
void	ft_lstadd_back(t_envp **lst, t_envp *new);

int	main(int argc, char *argv[], char *envp[])
{
	t_envp	*head;
	int		i;
	
	head = ft_lstnew(ft_strdup(envp[0]));

	i = 0;
	while(envp[i])
	{
		ft_lstadd_back(&head, ft_lstnew(envp[i]));
		i++;
	}
}
//ft_strdupを使って複製する理由として後々unsetコマンド(変数や関数を削除する)を使う
