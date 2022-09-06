#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

extern t_g	g_;

char	*tk_ques(char *cl, size_t B, char *(*f)(char *, size_t))
{
	char	s[32];
	size_t	i;
	char	*r;

	itosd(s, g_.exeret);
	i = strlen(s);/*  */
	r = (*f)(cl + 2, B + i);
	if (r)
		memcpy(r + B, s, i);/*  */
	return (r);
}
