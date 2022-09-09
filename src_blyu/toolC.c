#include "minishell.h"

int	is_numustr(char *s)
{
	if (*s == '-')
		s++;
	while (*s && ft_isdigit(*s))
		s++;
	if (!s)
		return (1);
	return (0);
}
