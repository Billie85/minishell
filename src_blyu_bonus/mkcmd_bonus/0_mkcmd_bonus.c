#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

char	*mkcmd(t_cmd *c, char *cl)
{
	char	*ncl;

	c->cmd = cmdlist(c, cl, &ncl, 0);
	if (!(c->cmd) && c->n_type != SYNTAXERROR)
		return (NULL);
	if (c->n_type == SYNTAXERROR)
		ncl = cl + ft_strlen(cl);
	return (ncl);
}
