/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecl_env_dq_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:00:45 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:00:46 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "envcl_bonus.h"

char	*ecl_env_dq1(char *cl, size_t B, char *env, size_t ii);

char	*ecl_env_dq(char *cl, size_t B)
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
	return (ecl_env_dq1(cl, B, env, ii));
}

char	*ecl_env_dq1(char *cl, size_t B, char *env, size_t ii)
{
	size_t	i;
	char	*r;

	if (env)
		i = ft_strlen(env);
	else
		i = 0;
	r = ecl_dq(cl + ii, B + i);
	if (!r || !*r)
		return (r);
	if (i)
		ft_memcpy(r + B, env, i);
	return (r);
}
