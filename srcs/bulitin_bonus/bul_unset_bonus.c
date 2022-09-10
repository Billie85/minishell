/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bul_unset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:59:35 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:59:36 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

int	bul_unset(int argc, char *argv[])
{
	size_t	i;
	size_t	ii;
	int		r;

	r = 0;
	i = 1;
	while ((int)i < argc)
	{
		ii = 0;
		while (ft_isalpha(argv[i][ii]) || argv[i][ii] == '_')
			ii++;
		if (argv[i][ii] == '\0')
		{
			rm_env(argv[i]);
		}
		else
			r = ep3("minishell: unset: `", argv[i] \
			, "': not a valid identifier\n");
		i++;
	}	
	return (r);
}
