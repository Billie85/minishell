/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkcmd_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:29 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:32:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MKCMD_BONUS_H
# define MKCMD_BONUS_H
# include "../minishell_bonus.h"

char	**cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll);
char	*tk_std(char *cl, size_t B);
char	*tk_dq(char *cl, size_t B);
char	*tk_sq(char *cl, size_t B);
char	*tk_ques(char *cl, size_t B, char *(*po)(char *, size_t));
char	*extractenv(char *cl);
#endif