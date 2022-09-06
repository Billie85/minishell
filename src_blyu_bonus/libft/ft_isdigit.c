/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:18:52 by blyu              #+#    #+#             */
/*   Updated: 2021/11/04 07:18:53 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int	c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
