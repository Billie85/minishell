/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:18:49 by blyu              #+#    #+#             */
/*   Updated: 2021/11/04 07:18:50 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int	c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}