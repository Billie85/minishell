#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*extractenv(char *cl)//too many functions in file
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	cl++;
	while (cl[i] && isalnum(cl[i]))
		i++;
//TESTn(i)
	r = malloc(i + 1);
	if (!r)
		return(m_error());
	if (i)
		memcpy(r, cl, i);
	r[i] = '\0';
//TEST
	return (r);
}
