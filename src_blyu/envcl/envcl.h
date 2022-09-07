/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:18:59 by blyu              #+#    #+#             */
/*   Updated: 2022/09/06 18:19:00 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVCL_H
# define ENVCL_H
# include "../minishell.h"

char	*ecl_std(char *cl, size_t B);
char	*ecl_dq(char *cl, size_t B);
char	*ecl_sq(char *cl, size_t B);
char	*ecl_sp(char *cl, size_t B);
char	*ecl_env_std(char *cl, size_t B);
char	*ecl_env_dq(char *cl, size_t B);
char	*extractenv(char *cl);

#endif