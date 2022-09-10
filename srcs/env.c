/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:05:55 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:05:56 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_space(char *s);

char	**ev(char **set)
{
	static char	**env = NULL;

	if (set)
		env = set;
	return (env);
}

char	*get_env(char *s)
{
	char	**env;
	size_t	l;

	l = 0;
	while (s[l])
	{
		if (s[l] == '=')
			return ("");
		l++;
	}
	env = ev(NULL);
	while (*env && !(!ft_strncmp(*env, s, l) && env[0][l] == '='))
		env++;
	if (!(*env))
		return ("");
	return ((*env) + l + 1);
}

int	set_env(char *name, char *arg)
{
	char		**env;
	char		*s;
	size_t		l;

	s = malloc(ft_strlen(name) + ft_strlen(arg) + 2);
	if (!s)
	{
		printf("malloc error\n");
		return (1);
	}
	l = ft_strlen(name);
	ft_memcpy(s, name, l);
	s[l] = '=';
	l++;
	ft_memcpy(s + l, arg, ft_strlen(arg));
	s[l + ft_strlen(arg)] = '\0';
	env = env_space(name);
	if (!env)
		return (1);
	*env = s;
	return (0);
}

char	**env_space(char *s)
{
	char	**env;
	char	**r;
	size_t	i;
	size_t	l;

	env = ev(NULL);
	i = 0;
	l = ft_strlen(s);
	while (env[i] && !(!ft_strncmp(env[i], s, l) && env[i][l] == '='))
		i++;
	if (env[i])
		return (free_return(env[i], env + i));
	r = malloc((i + 2) * sizeof(char **));
	if (!r)
		return (m_error());
	i = 0;
	while (env[i])
	{
		r[i] = env[i];
		i++;
	}
	free(env);
	r[i + 1] = NULL;
	return (ev(r) + i);
}

int	rm_env(char *s)
{
	char	**env;
	size_t	i;
	size_t	l;

	env = ev(NULL);
	i = 0;
	l = ft_strlen(s);
	while (env[i] && ! (!ft_strncmp(env[i], s, l) && env[i][l] == '='))
		i++;
	if (!env[i])
		return (1);
	free(env[i]);
	while (env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
	return (0);
}
