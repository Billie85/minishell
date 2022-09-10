/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:04:08 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:04:09 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		i = 0;
		while (s1[i] == s2[i] && s2[i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char *)s1);
		else
			s1++;
	}
	return (NULL);
}
