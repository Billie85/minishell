#include "minishell2.h"
//#include "debug.h"

char	*full_file_neme(char	*s)
{
	char	pathname[PATHNAME_SIZE];
	char	*r;
	size_t	i;

	getcwd(pathname, PATHNAME_SIZE);
	if (*s == '/')
		r = strdup(s);
	else if (*s == '.')
		r = ft_strjoin(pathname, s + 1);
	else if (*s == '~')
		r = ft_strjoin(get_env("HOME"), s + 1);
	else
	{
		i = strlen(pathname);
		pathname[i] = '/';
		pathname[i + 1] = '\0';
		r = ft_strjoin(pathname, s);
	}
	if (!r)
		printf("malloc error\n");
	return (r);
}

char	*skip_tk(char *cl)
{
	char	c;

	while (*cl == ' ')
		cl++;
	while (*cl && *cl != ' ')
	{
		if (*cl == '"' || *cl == '\'')
		{
			c = *cl;
			cl++;
			while (*cl != c)
				cl++;
			cl++;
		}
		else if (*cl == '\\')
			cl += 2;
		else
			cl++;
	}
	while (*cl == ' ')
		cl++;
	return (cl);
}
