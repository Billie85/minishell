#include "../minishell_bonus.h"
#include "asterisk.h"

size_t	as_std_aslen(char *cl)
{
	size_t	i;

	i = 0;
	while (cl[i] && cl[i] != '*' && cl[i] != ' ')
	{
		if (cl[i] == '"')
		{
			i++;
			while (cl[i] != '"')
				i++;
			i++;
		}
		else if (cl[i] == '\'')
		{
			i++;
			while (cl[i] != '\'')
				i++;
			i++;
		}
		else if (cl[i] == '\\')
			i += 2;
		else
			i++;
	}
	return (i);
}
