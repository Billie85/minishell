#include "minishell.h"

char	*cm_name1(char *s);
char	*cm_name2(char *p, char *s);
int		isexe(char *s);

char	*cm_name(char *s)
{
	char	*r;

	if (*s == '/' || *s == '.')
		r = ft_strdup(s);
	else if (*s == '~')
		r = ft_strjoin(get_env("HOME"), s + 1);
	else
		r = cm_name1(s);
	if (r && !isexe(r))
	{
		free(r);
		printf("no such command %s\n", s);
		r = ft_strdup("");
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
	f = 0;
	while (path[f])
	{
		r = cm_name2(path + f, s);
		if (!r)
			return (NULL);
		else if (isexe(r))
			return (r);
		else
			free(r);
		while (path[f] && path[f] != ':')
			f++;
		if (path[f] == ':')
			f++;
	}
	return (ft_strdup(""));
}

char	*cm_name2(char *p, char *s)
{
	char	*r;
	size_t	i;
	size_t	ii;

	i = 0;
	while (p[i] && p[i] != ':')
		i++;
	r = malloc(i + ft_strlen(s) + 2);
	if (!r)
		return (m_error());
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
		r[i++] = s[ii++];
	r[i] = '\0';
	return (r);
}

int	isexe(char *s)
{
	DIR	*dir;

	if (!access(s, X_OK))
	{
		dir = opendir(s);
		if (!dir)
			return (1);
		closedir(dir);
	}
	return (0);
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
