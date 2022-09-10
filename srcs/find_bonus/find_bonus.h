/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:02:19 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:02:20 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BONUS_H
# define FIND_BONUS_H
# include "../minishell_bonus.h"

typedef struct s_dirs
{
	DIR				*dir;
	char			*str;
	struct s_dirs	*befor;
}	t_dirs;

char	**fi_list(char *search);
char	**fi_std(t_dirs *d, size_t dw);
void	fi_dir(char **r);
int		fi_ok(char *str, char **l);
#endif