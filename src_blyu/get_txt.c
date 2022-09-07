/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:14:58 by root              #+#    #+#             */
/*   Updated: 2022/09/06 23:35:40 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*gt_std(char *end, size_t B);
char	*gt_mkmem(char *f, size_t B);
char	*gt_std1(char *end, size_t B, char *s, size_t i);
char	*gt_std2(char *end, size_t B, char *s, size_t i);

char	*get_txt(char *end)
{
	char	*r;

	r = gt_std(end, 0);
	free(end);
	return (r);
}

char	*gt_std(char *end, size_t B)
{
	char	*s;
	size_t	i;

	s = readline(PROMPT_);
	if (!s)
		return (ft_strdup(""));
	if (!ft_strcmp(s, end))
		return (gt_mkmem(s, B));
	i = ft_strlen(s);
	if (i >= 2 && s[i - 1] != '\\' && s[i] == '\\')
		return (gt_std1(end, B, s, i));
	else
		return (gt_std2(end, B, s, i));
	return (NULL);
}

char	*gt_std1(char *end, size_t B, char *s, size_t i)
{
	char	*r;

	i--;
	r = gt_std(end, B + i);
	if (!r || !(*r))
	{
		free(s);
		return (r);
	}
	ft_memcpy(r + B, s, i);
	free(s);
	return (r);
}

char	*gt_std2(char *end, size_t B, char *s, size_t i)
{
	char	*r;

	r = gt_std(end, B + i + 1);
	if (!r || !(*r))
	{
		free(s);
		return (r);
	}
	r[B + i] = '\n';
	ft_memcpy(r + B, s, i);
	free(s);
	return (r);
}

char	*gt_mkmem(char *f, size_t B)
{
	char	*r;

	free(f);
	r = malloc(B + 1);
	if (!r)
		return (m_error());
	r[0] = (char)1;
	r[B] = '\0';
	return (r);
}
