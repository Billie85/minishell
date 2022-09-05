#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	*tk_std4(char *cl, size_t B, size_t i)
{
	char	*r;

	r = tk_dq(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_std5(char *cl, size_t B, size_t i)
{
	char	*r;

	r = tk_sq(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
