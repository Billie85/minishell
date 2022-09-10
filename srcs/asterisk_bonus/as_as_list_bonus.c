/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_as_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:58:09 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 21:58:10 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "asterisk_bonus.h"

char	**as_as_list1(size_t dw);
char	**as_as_list2(char *cl, size_t dw);
char	**as_as_list3(char *cl, size_t dw);
char	**as_as_list4(char *cl, size_t dw);

char	**as_as_list(char *cl, size_t dw)
{
	if (*cl == '\0' || *cl == ' ')
		return (as_as_list1(dw));
	else if (*cl == '*' && !dw)
		return (as_as_list2(cl, dw));
	else if (*cl == '*')
		return (as_as_list3(cl, dw));
	else
		return (as_as_list4(cl, dw));
}

char	**as_as_list1(size_t dw)
{
	char	**r;

	r = malloc((dw + 1) * sizeof(char *));
	if (!r)
		return (m_error());
	r[dw] = NULL;
	return (r);
}

char	**as_as_list2(char *cl, size_t dw)
{
	char	**r;
	char	*s;

	s = ft_strdup("");
	if (!s)
		return (m_error());
	while (*cl == '*')
		cl++;
	r = as_as_list(cl, 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	r[dw] = s;
	return (r);
}

char	**as_as_list3(char *cl, size_t dw)
{
	char	**r;
	char	*s;

	while (*cl == '*')
		cl++;
	if (*cl == '\0')
	{
		s = ft_strdup("");
		if (!s)
			return (m_error());
		r = as_as_list(cl, dw + 1);
		if (!r)
		{
			free(s);
			return (NULL);
		}
		r[dw] = s;
		return (r);
	}
	else
		return (as_as_list(cl, dw));
}

char	**as_as_list4(char *cl, size_t dw)
{
	char	**r;
	char	*s;

	s = as_as_std(cl, &cl, 0);
	if (!s)
		return (m_error());
	r = as_as_list(cl, dw + 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	r[dw] = s;
	return (r);
}
