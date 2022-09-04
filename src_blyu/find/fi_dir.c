#include "../minishell.h"
#include "find.h"

#include "../debug.h"

void	fi_dir(char **r)
{
	size_t	i;
	size_t	ii;
	size_t	l;

	i = 0;
	ii = 0;
	while (r[i])
	{
		l = strlen(r[i]);
		if ((l >= 2 && r[i][l - 2] == '/' && r[i][l - 1] == '.') || (l == 1 && r[i][0] == '.'))//line long
		{
//TEST
			r[i][l - 2] = '\0';
			if (r[i + 1] && !strncmp(r[i + 1], r[i], strlen(r[i])))
				free(r[i]);
			else
			{
				r[ii] = r[i];
				ii++;
			}
		}
		else
		{
			r[ii] = r[i];
			ii++;
		}
		i++;
	}
	r[ii] = NULL;
}//25
