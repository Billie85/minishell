#ifndef FIND_H
# define FIND_H
# include "../minishell.h"

typedef struct s_dirs
{
	DIR				*dir;
	char			*str;
	struct s_dirs	*befor;
}	t_dirs;

char	**fi_list(char *search);
char	**fi_std(t_dirs *d, size_t dw);
void	fi_dir(char **r);
int		fi_ok(char *str, char **l);
#endif