#include "minishell.h"
#include "debug.h"

typedef struct s_dirs
{
	DIR				*dir;
	char			*str;
	struct s_dirs	*befor;
}	t_dirs;

char	**fi_list(char *search);
char    **fi_std(t_dirs *d, size_t dw);
void	fi_dir(char **r);
int		fi_ok(char *str, char **l);

char	**find(char **lst)
{
	char	**l;
	size_t	i;
	size_t	ii;

	l = fi_list(lst[0]);
	if (!l)
		return (NULL);
	i = 0;
	ii = 0;
	while (l[i])
	{
		if (fi_ok(l[i], lst))
		{
			l[ii] = l[i];
			ii++;
		}
		else
			free(l[i]);
		i++;
	}
	l[ii] = NULL;
	return (l);
}

char	**fi_list(char *search)
{
	char	c;
	size_t	i;
	t_dirs	d;
	char	**r;

	i = strlen(search);
	while (i && search[i] != '/')
		i--;
	if (search[i] == '/')
	{
		c = search[i + 1];
		search[i + 1] = '\0';
		d.dir = opendir(search);
//TESTp(d.dir)
		if (!(d.dir))
		{
			r = malloc(sizeof(char **));
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			*r = NULL;
			return (r);
		}
		d.str = search;
		d.befor = NULL;
		r = fi_std(&d, 0);
		search[i + 1] = c;
		if (!r)
			return (NULL);
		fi_dir(r);
	}
	else
	{
		d.dir = opendir("./");
		if (!(d.dir))
		{
			r = malloc(sizeof(char **));
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			*r = NULL;
			return (r);
		}
		d.str = "./";
		d.befor = NULL;
		r = fi_std(&d, 0);
		if (!r)
			return (NULL);
		fi_dir(r);
		size_t	ii = 0;
		while (r[ii])
		{
			memmove(r[ii], r[ii] + 2, strlen(r[ii] + 2) + 1);/*  */
			ii++;
		}
	}
	return (r);
}


char    **fi_std(t_dirs *d, size_t dw)
{
	t_dirs	nd;
	char	**r;
	char	*s;
	struct dirent *dent;

	if (!d)
	{
		r = malloc((dw + 1) * sizeof(char **));
		if (!r)
		{
			printf("malloc error\n");
			return (NULL);
		}
		*r = NULL;
		return (r);
	}
	dent = readdir(d->dir);
	if(!dent)
	{
		closedir(d->dir);
		return (fi_std(d->befor, dw));
	}
	if (!strcmp(dent->d_name, ".."))
		return (fi_std(d, dw));
	else if (dent->d_type != DT_DIR || !strcmp(dent->d_name, "."))
	{
		s = ft_strjoin(d->str, dent->d_name);
		if (!s)
		{
			printf("malloc error\n");
			return (NULL);
		}
		r = fi_std(d, dw + 1);
		if (!r)
			return (NULL);
		r[dw] = s;
		return (r);
	}
	else if (strcmp(dent->d_name, "..") && dent->d_type == DT_DIR)
	{
		size_t	i;
		size_t	ii;

		i = strlen(d->str);
		ii = strlen(dent->d_name);
		s = malloc(i + ii + 2);
		if (!s)
		{
			printf("malloc error\n");
			return (NULL);
		}
		memcpy(s, d->str, i);
		memcpy(s + i, dent->d_name, ii);
		s[i + ii] = '/';
		s[i + ii + 1] = '\0';
		nd.befor = d;
		nd.str = s;
		nd.dir = opendir(s);
		r = fi_std(&nd, dw);
		free(nd.str);
		return (r);
	}
	else
{
		return (fi_std(d, dw));
}
}

void	fi_dir(char **r)
{
	size_t	i = 0;
	size_t	ii = 0;
	size_t	l;

	while (r[i])
	{
		l = strlen(r[i]);
		if ((l >= 2 && r[i][l - 2] == '/' && r[i][l - 1] == '.') || (l == 1 && r[i][0] == '.'))
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
}

int	fi_ok(char *str, char **l)
{
	size_t	i;
	size_t	ii;

	if(l[0][0] != '\0' && strncmp(str, l[0], strlen(l[0])))/*  */
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
	if (strncmp(str + i - ii, *l, ii))/*  */
		return (0);
	return (1);
}


/* 
int main(int argc, char *argv[]) {

	if (argc <= 1)
		return (0);
	for (size_t i = 1; argv[i]; i++)
	{
		printf("%zu\t:%s[\\n]\n", i, argv[i]);
	}
//TEST_
	char	**t = find(argv + 1);	
	for (size_t i = 0; t[i]; i++)
	{
		printf("%zu\t:%s[\\n]\n", i, t[i]);
	}
	return 0;
}
 */