#include "../minishell.h"
#include "find.h"

#include "../debug.h"

char	**fi_list(char *search)
{
	char	c;
	size_t	i;
	t_dirs	d;
	char	**r;
	size_t	ii;

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
				return(m_error());
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
				return(m_error());
			*r = NULL;
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
	}
	return (r);
}//25
