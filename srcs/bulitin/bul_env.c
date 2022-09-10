/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bul_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:58:49 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:58:50 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
