/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:58:32 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:58:33 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERISK_BONUS_H
# define ASTERISK_BONUS_H
# include "../minishell_bonus.h"

char	*as_std(char *cl, size_t B);
char	**as_as_list(char *cl, size_t dw);
char	*as_as_std(char *cl, char **cln, size_t B);
char	*as_as_q(char *cl, char **cln, size_t B, char c);

#endif