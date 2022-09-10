/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envcl_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:01:16 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:01:17 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVCL_BONUS_H
# define ENVCL_BONUS_H
# include "../minishell_bonus.h"

char	*ecl_std(char *cl, size_t B);
char	*ecl_dq(char *cl, size_t B);
char	*ecl_sq(char *cl, size_t B);
char	*ecl_sp(char *cl, size_t B);
char	*ecl_env_std(char *cl, size_t B);
char	*ecl_env_dq(char *cl, size_t B);
char	*extractenv(char *cl);

#endif