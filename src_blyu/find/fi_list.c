#include "../minishell.h"
#include "find.h"

#include "../debug.h"

char	**fi_list1(char *search, size_t	i);
char	**fi_list2(char *search, size_t	i);

char	**fi_list(char *search)
{
	size_t	i;
	char	c;
	t_dirs	d;
	char	**r;
	size_t	ii;

	i = strlen(search);
	while (i && search[i] != '/')
		i--;
	if (search[i] == '/')
		return (fi_list1(search, i));
	else
		return (fi_list2(search, i));
	return (NULL);
}

char	**fi_list1(char *search, size_t	i)
{
	char	c;
	t_dirs	d;
	char	**r;

	c = search[i + 1];
	search[i + 1] = '\0';
	d.dir = opendir(search);
	if (!(d.dir))
	{
		r = malloc(sizeof(char **));
		if (!r)
			return (m_error());
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
	return (r);
}

char	**fi_list2(char *search, size_t	i)
{
	t_dirs	d;
	char	**r;
	size_t	ii;

	d.dir = opendir("./");
	if (!(d.dir))
	{
		r = calloc(1, sizeof(char **));/*  */
		if (!r)
			return (m_error());
		return (r);
	}
	d.str = "./";
	d.befor = NULL;
	r = fi_std(&d, 0);
	if (!r)
		return (NULL);
	fi_dir(r);
	ii = 0;
	while (r[ii])
	{
		memmove(r[ii], r[ii] + 2, strlen(r[ii] + 2) + 1);/*  */
		ii++;
	}
	return (r);
}
