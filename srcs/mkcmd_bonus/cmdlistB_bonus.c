/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlistB_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:04:52 by blyu              #+#    #+#             */
/*   Updated: 2022/09/10 22:04:53 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

int	cmdlist4_sendtxt(char *s);

char	**cmdlist4(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	cl += 2;
	while (*cl == ' ')
		cl++;
	s = tk_std(cl, 0);
	if (!s)
		return (NULL);
	else if ((!(*s) && !(*cl)) \
	|| *s == '<' || *s == '>' || *s == '|' || !ft_strcmp(s, "&&"))
	{
		printf("syntax error\n");
		free(s);
		c->n_type = SYNTAXERROR;
		return (NULL);
	}
	cl = skip_tk(cl);
	if (c->pipe[R_PIPE] >= 0)
		close(c->pipe[R_PIPE]);
	c->pipe[R_PIPE] = cmdlist4_sendtxt(s);
	r = cmdlist(c, cl, ncl, ll);
	return (r);
}

int	cmdlist4_sendtxt(char	*s)
{
	int	fd[2];

	pipe(fd);
	s = get_txt(s);
	if (!s)
		return (-1);
	write(fd[W_PIPE], s, ft_strlen(s));
	close(fd[W_PIPE]);
	free(s);
	return (fd[R_PIPE]);
}

char	**cmdlist5(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	cl += 2;
	while (*cl == ' ')
		cl++;
	s = tk_std(cl, 0);
	cl = skip_tk(cl);
	if (!s)
		return (NULL);
	else if (!*s || *s == '<' || *s == '>' || *s == '|' || !ft_strcmp(s, "&&"))
	{
		printf("syntax error\n");
		free(s);
		c->n_type = SYNTAXERROR;
		return (NULL);
	}
	if (c->pipe[W_PIPE] >= 0)
		close(c->pipe[W_PIPE]);
	c->pipe[W_PIPE] = open(s, O_WRONLY | O_CREAT | O_APPEND, \
	S_IREAD | S_IWRITE);
	free(s);
	r = cmdlist(c, cl, ncl, ll);
	return (r);
}
