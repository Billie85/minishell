/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bul_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:59:23 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:59:24 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

int	bul_env(int argc, char *argv[])
{
	char	**env;

	(void) argc;
	(void) argv;
	env = ev(NULL);
	if (!env)
		return (1);
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
