#include "../minishell_bonus.h"
#include "asterisk_bonus.h"

char	*asterisk(char *cl)
{
	char	*r;

	r = as_std(cl, 0);
	free(cl);
	return (r);
}
