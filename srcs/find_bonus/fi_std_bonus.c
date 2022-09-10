/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_std_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:02:14 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:02:15 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "find_bonus.h"

char	**fi_std1(size_t dw);
char	**fi_std2(t_dirs *d, size_t dw);
char	**fi_std3(t_dirs *d, size_t dw, struct dirent *dent);
char	**fi_std4(t_dirs *d, size_t dw, struct dirent *dent);

char	**fi_std(t_dirs *d, size_t dw)
{
	struct dirent	*dent;

	if (!d)
		return (fi_std1(dw));
	dent = readdir(d->dir);
	if (!dent)
		return (fi_std2(d, dw));
	else if (!ft_strcmp(dent->d_name, ".."))
		return (fi_std(d, dw));
	else if (dent->d_type != DT_DIR || !ft_strcmp(dent->d_name, "."))
		return (fi_std3(d, dw, dent));
	else if (ft_strcmp(dent->d_name, "..") && dent->d_type == DT_DIR)
		return (fi_std4(d, dw, dent));
	else
		return (fi_std(d, dw));
}

char	**fi_std1(size_t dw)
{
	char	**r;

	r = malloc((dw + 1) * sizeof(char **));
	if (!r)
		return (m_error());
	r[dw] = NULL;
	return (r);
}

char	**fi_std2(t_dirs *d, size_t dw)
{
	closedir(d->dir);
	return (fi_std(d->befor, dw));
}

char	**fi_std3(t_dirs *d, size_t dw, struct dirent *dent)
{
	char	*s;
	char	**r;

	s = ft_strjoin(d->str, dent->d_name);
	if (!s)
		return (m_error());
	r = fi_std(d, dw + 1);
	if (!r)
		return (NULL);
	r[dw] = s;
	return (r);
}

char	**fi_std4(t_dirs *d, size_t dw, struct dirent *dent)
{
	t_dirs	nd;
	char	**r;
	char	*s;
	size_t	i;
	size_t	ii;

	i = ft_strlen(d->str);
	ii = ft_strlen(dent->d_name);
	s = malloc(i + ii + 2);
	if (!s)
		return (m_error());
	ft_memcpy(s, d->str, i);
	ft_memcpy(s + i, dent->d_name, ii);
	s[i + ii] = '/';
	s[i + ii + 1] = '\0';
	nd.befor = d;
	nd.str = s;
	nd.dir = opendir(s);
	r = fi_std(&nd, dw);
	free(nd.str);
	return (r);
}
