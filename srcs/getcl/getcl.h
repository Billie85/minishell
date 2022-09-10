/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:03:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:03:02 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETCL_H
# define GETCL_H
# include "../minishell.h"

char	*gcl_std(char	*cl, size_t	B);
char	*gcl_dq(char	*cl, size_t	B);
char	*gcl_sq(char	*cl, size_t	B);
char	*gcl_nc(char	*cl, size_t	B);
#endif