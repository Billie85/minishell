#ifndef MKCMD_H
#define MKCMD_H
#include "../minishell.h"
char	**cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll);
char	*tk_std(char *cl, size_t B);
char	*tk_dq(char *cl, size_t B);
char	*tk_sq(char *cl, size_t B);
char	*tk_ques(char *cl, size_t B, char *(*po)(char *, size_t));
char	*extractenv(char *cl);
#endif