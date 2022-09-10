/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:57:58 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:57:59 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERISK_H
# define ASTERISK_H
# include "../minishell.h"

char	*as_std(char *cl, size_t B);
char	**as_as_list(char *cl, size_t dw);
char	*as_as_std(char *cl, char **cln, size_t B);
char	*as_as_q(char *cl, char **cln, size_t B, char c);

#endif