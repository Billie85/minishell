/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_ques_g_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:05:15 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:05:16 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

extern t_g	g_;

char	*tk_ques(char *cl, size_t B, char *(*f)(char *, size_t))
{
	char	s[32];
	size_t	i;
	char	*r;

	itosd(s, g_.exeret);
	i = ft_strlen(s);
	r = (*f)(cl + 2, B + i);
	if (r)
		ft_memcpy(r + B, s, i);
	return (r);
}
