/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:59:52 by blyu              #+#    #+#             */
/*   Updated: 2021/11/23 12:40:41 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	ft_striteri(char	*s, void	(*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*(s + i))
	{
		(*f)(i, s + i);
		i++;
	}
}
