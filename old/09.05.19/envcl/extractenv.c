#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*extractenv(char *cl)
{
	size_t	i;
	char	*r;

	i = 0;
	cl++;
	while (cl[i] && isalnum(cl[i]))
		i++;
	r = malloc(i + 1);
	if (!r)
		return(m_error());
	if (i)
		memcpy(r, cl, i);
	r[i] = '\0';
	return (r);
}
