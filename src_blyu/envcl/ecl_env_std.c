/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecl_env_std.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:18:34 by blyu              #+#    #+#             */
/*   Updated: 2022/09/06 18:18:35 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envcl.h"

char	*ecl_env_std1(char *cl, size_t B, char *env, size_t ii);

char	*ecl_env_std(char *cl, size_t B)
{
	char	*envname;
	char	*env;
	size_t	ii;

	envname = extractenv(cl);
	if (!envname)
		return (NULL);
	if (*envname)
	{
		cl++;
		env = get_env(envname);
		ii = ft_strlen(envname);
	}
	else
	{
		env = "$";
		ii = 1;
	}
	free(envname);
	return (ecl_env_std1(cl, B, env, ii));
}

char	*ecl_env_std1(char *cl, size_t B, char *env, size_t ii)
{
	size_t	i;
	char	*r;

	if (env)
		i = ft_strlen(env);
	if (cl[ii] == ' ' || cl[ii] == '<' || cl[ii] == '>' \
	|| cl[ii] == '|' || cl[ii] == ';' || !ft_strncmp(cl + ii, "&&", 2))
	{
		r = ecl_sp(cl + ii, B + i + 1);
		if (!r || !*r)
			return (r);
		r[B + i] = ' ';
	}
	else
	{
		r = ecl_std(cl + ii, B + i);
		if (!r || !*r)
			return (r);
	}
	if (i)
		ft_memcpy(r + B, env, i);
	return (r);
}
