#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

extern int	exeret;//global g

char	*tk_ques(char *cl, size_t B, char *(*f)(char *, size_t))//too manyu funcyions
{
	char	s[32];
	size_t	i;
	char	*r;

	itosd(s, exeret);
	i = strlen(s);/*  */
	r = (*f)(cl + 2, B + i);
	if (r)
		memcpy(r + B, s, i);/*  */
	return (r);
}
