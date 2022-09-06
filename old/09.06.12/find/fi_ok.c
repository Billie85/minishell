#include "../minishell.h"
#include "find.h"

#include "../debug.h"

int	fi_ok(char *str, char **l)
{
	size_t	i;
	size_t	ii;

	if (l[0][0] != '\0' && strncmp(str, l[0], strlen(l[0])))/*  */
		return (0);
	l++;
	if (!l[0])
		return (1);
	while (l[1])
	{
		str = strstr(str, *l);/*  */
		if (!str)
			return (0);
		str += strlen(*l);/*  */
		l++;
	}
	if (**l == '\0')
		return (1);
	i = strlen(str);
	ii = strlen(*l);
	if (i < ii)
		return (0);
	if (strncmp(str + i - ii, *l, ii))/* */
		return (0);
	return (1);
}
