#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*envcl(char *cl)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] == ' ' && cl[i])
		i++;
	r = ecl_std(cl + i, 0);
	free(cl);
	return (r);
}
