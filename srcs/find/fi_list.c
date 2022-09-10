/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:01:36 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:01:37 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "find.h"

char	**fi_list1(char *search, size_t	i);
char	**fi_list2(void);

char	**fi_list(char *search)
{
	size_t	i;

	i = ft_strlen(search);
	while (i && search[i] != '/')
		i--;
	if (search[i] == '/')
		return (fi_list1(search, i));
	else
		return (fi_list2());
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

char	**fi_list2(void)
{
	t_dirs	d;
	char	**r;
	size_t	ii;

	d.dir = opendir("./");
	if (!(d.dir))
	{
		r = ft_calloc(1, sizeof(char **));
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
		ft_memmove(r[ii], r[ii] + 2, ft_strlen(r[ii] + 2) + 1);
		ii++;
	}
	return (r);
}
