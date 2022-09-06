#ifndef ASTERISK_BONUS_H
# define ASTERISK_BONUS_H //bad prprocessor indentation
# include "../minishell.h"

char	*as_std(char *cl, size_t B);
char	**as_as_list(char *cl, size_t dw);
char	*as_as_std(char *cl, char **cln, size_t B);
char	*as_as_q(char *cl, char **cln, size_t B, char c);

#endif