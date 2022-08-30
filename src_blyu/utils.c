#include "minishell.h"

char	*full_file_neme(char	*s)
{
	char pathname[PATHNAME_SIZE];
	char *r;
	size_t	i;

	getcwd(pathname, PATHNAME_SIZE);
	if (*s == '/')
		r = strdup(s);
	else if (*s == '.')
		r = ft_strjoin(pathname, s + 1);
	else if (*s == '~')
		r = ft_strjoin(getenv("HOME"), s + 1);
	else
	{
		i = strlen(pathname);/*  */
		pathname[i] = '/';
		pathname[i + 1] = '\0';		
		r = ft_strjoin(pathname, s);
	}
	if (!r)
		printf("malloc error\n");
	return (r);
}