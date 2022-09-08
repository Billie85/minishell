#include "minishell.h"

int	isexe(char *s)
{
	struct dirent	*dent;

	if (access(s, X_OK))
		return (0);
	dent = opendir(s);
	if (!dent)
		return (1);
	closedir(dent);
	return (0);
}