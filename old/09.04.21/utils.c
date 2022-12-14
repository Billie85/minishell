#include "minishell.h"
#include "debug.h"

char	*full_file_neme(char	*s)
{
	char	pathname[PATHNAME_SIZE];
	char	*r;
	size_t	i;

	getcwd(pathname, PATHNAME_SIZE);
	if (*s == '/')
		r = strdup(s);/*  */
	else if (*s == '.')
		r = ft_strjoin(pathname, s + 1);
	else if (*s == '~')
		r = ft_strjoin(get_env("HOME"), s + 1);
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

char	*cm_name1(char *s);
char	*cm_name2(char *p, char *s);

char	*cm_name(char *s)
{
	char	pathname[PATHNAME_SIZE];
	char	*r;

	getcwd(pathname, PATHNAME_SIZE);
	if (*s == '/')
		r = strdup(s);/*  */
	else if (*s == '.')
		r = ft_strjoin(pathname, s + 1);
	else if (*s == '~')
		r = ft_strjoin(get_env("HOME"), s + 1);
	else
		r = cm_name1(s);
	if (r && access(r, X_OK))
	{
		free(r);
		printf("no such comand %s\n", s);
		r = strdup("");/*  */
	}
	if (!r)
		printf("malloc error\n");
	return (r);
}

char	*cm_name1(char *s)
{
	char	*path;
	char	*r;
	size_t	f;

	path = get_env("PATH");
	f = strlen(path);
	while (f)
	{
		while (f && path[f] != ':')
			f--;
		if (path[f] == ':')
			r = cm_name2(path + f + 1, s);
		else
			r = cm_name2(path + f, s);
		if (!r)
			return (NULL);
		else if (!access(r, X_OK))
			return (r);
		else
			free(r);
		if (path[f] == ':')
			f--;
	}
	return (strdup(""));/*  */
}

char	*cm_name2(char *p, char *s)
{
	char	*r;
	size_t	i;
	size_t	ii;

	i = 0;
	while (p[i] && p[i] != ':')
		i++;
	r = malloc(i + strlen(s) + 2);
	if (!r)
		return(m_error());
	i = 0;
	while (p[i] && p[i] != ':')
	{
		r[i] = p[i];
		i++;
	}
	r[i] = '/';
	i++;
	ii = 0;
	while (s[ii] && s[ii] != ':')
	{
		r[i] = s[ii];
		i++;
		ii++;
	}
	r[i] = '\0';
	return (r);
}//25

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
