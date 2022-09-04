#include "../minishell.h"
#include "find.h"

#include "../debug.h"

char	**fi_std(t_dirs *d, size_t dw)
{
	struct dirent	*dent;
	t_dirs			nd;
	char			**r;
	char			*s;

	if (!d)
	{
		r = malloc((dw + 1) * sizeof(char **));
		if (!r)
			return(m_error());
		r[dw] = NULL;
		return (r);
	}
	dent = readdir(d->dir);
	if (! dent)
	{
		closedir(d->dir);
		return (fi_std(d->befor, dw));
	}
	if (!strcmp(dent->d_name, ".."))
		return (fi_std(d, dw));
	else if (dent->d_type != DT_DIR || !strcmp(dent->d_name, "."))//DI_DIRが定義されていません。
	{
		s = ft_strjoin(d->str, dent->d_name);
		if (!s)
			return(m_error());
		r = fi_std(d, dw + 1);
		if (!r)
			return (NULL);
		r[dw] = s;
		return (r);
	}
	else if (strcmp(dent->d_name, "..") && dent->d_type == DT_DIR)
	{
		size_t	i;//?
		size_t	ii;//?

		i = strlen(d->str);
		ii = strlen(dent->d_name);
		s = malloc(i + ii + 2);
		if (!s)
			return(m_error());
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
}//25
