#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	**cmdlist1(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist2(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist3(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist4(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist5(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist6(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist7(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist8(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist9(t_cmd *c, char *cl, char **ncl, size_t ll);
char	**cmdlist0(t_cmd *c, char *cl, char **ncl, size_t ll);

char	**cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	while (*cl == ' ')
		cl++;
	if (!*cl)
		return (cmdlist1(c, cl, ncl, ll));
	else if (!strncmp(cl, "< ", 2))/*  */
		return (cmdlist2(c, cl, ncl, ll));
	else if (!strncmp(cl, "> ", 2))/*  */
		return (cmdlist3(c, cl, ncl, ll));
	else if (!strncmp(cl, "<< ", 3))/*  */
		return (cmdlist4(c, cl, ncl, ll));
	else if (!strncmp(cl, ">> ", 3))/*  */
		return (cmdlist5(c, cl, ncl, ll));
	else if (!strncmp(cl, "| ", 2))/*  */
		return (cmdlist6(c, cl, ncl, ll));
	else if (!strncmp(cl, "; ", 2))/*  */
		return (cmdlist7(c, cl, ncl, ll));
	else if (!strncmp(cl, "|| ", 3))/*  */
		return (cmdlist8(c, cl, ncl, ll));
	else if (!strncmp(cl, "&& ", 3))/*  */
		return (cmdlist9(c, cl, ncl, ll));
	else
		return (cmdlist0(c, cl, ncl, ll));
	return (NULL);
}

char	**cmdlist1(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	r = malloc(sizeof(char **) * ll + 1);
	if (!r)
		return(NULL);
	*ncl = cl;
	if (c->n_type != SKIP)
		c->n_type = CONTINUE;
	r[0] = (char *)1;
	r[ll] = NULL;
	return (r);
}

char	**cmdlist2(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	cl++;
	while (*cl == ' ')
		cl++;
	s = tk_std(cl, 0);
	cl = skip_tk(cl);
	if (!s)
		return (NULL);
	else if (!*s || *s == '<' || *s == '>' || *s == '|' || !strcmp(s, "&&"))
	{
		printf("syntax error\n");
		free(s);
		c->n_type = SYNTAXERROR;
		return (NULL);
	}
	if (c->pipe[R_PIPE] >= 0)
		close(c->pipe[R_PIPE]);
	c->pipe[R_PIPE] = open(s, O_RDONLY | O_CREAT, S_IREAD | S_IWRITE);//S_IERITE?????????????????????????????????
	free(s);
	r = cmdlist(c, cl, ncl, ll);
	return (r);
}

char	**cmdlist3(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	cl++;
	while (*cl == ' ')
		cl++;
	s = tk_std(cl, 0);
	cl = skip_tk(cl);
	if (!s)
		return (NULL);
	else if (!*s || *s == '<' || *s == '>' || *s == '|' || !strcmp(s, "&&"))
	{
		printf("syntax error\n");
		free(s);
		c->n_type = SYNTAXERROR;
		return (NULL);
	}
	if (c->pipe[W_PIPE] >= 0)
		close(c->pipe[W_PIPE]);
	c->pipe[W_PIPE] = open(s, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);//S_IREAD?????????????????????????????????
	free(s);
	r = cmdlist(c, cl, ncl, ll);
	return (r);
}

char	**cmdlist4(t_cmd *c, char *cl, char **ncl, size_t ll)
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
	else if (!*s || *s == '<' || *s == '>' || *s == '|' || !strcmp(s, "&&"))
	{
		printf("syntax error\n");
		free(s);
		c->n_type = SYNTAXERROR;
		return (NULL);
	}
	int	fd[2];//
	pipe(fd);
	s = get_txt(s);
	if (!s)
		return (NULL);
TESTs(s)
	write(fd[W_PIPE], s, strlen(s));
	close(fd[W_PIPE]);
	free(s);
	if (c->pipe[R_PIPE] >= 0)
		close(c->pipe[R_PIPE]);
	c->pipe[R_PIPE] = fd[R_PIPE];
	r = cmdlist(c, cl, ncl, ll);
	return (r);
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
	else if (!*s || *s == '<' || *s == '>' || *s == '|' || !strcmp(s, "&&"))
	{
		printf("syntax error\n");
		free(s);
		c->n_type = SYNTAXERROR;
		return (NULL);
	}
	if (c->pipe[W_PIPE] >= 0)
		close(c->pipe[W_PIPE]);
	c->pipe[W_PIPE] = open(s, O_WRONLY | O_CREAT | O_APPEND, S_IREAD | S_IWRITE);//line too long
	free(s);
	r = cmdlist(c, cl, ncl, ll);
	return (r);
}

char	**cmdlist6(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	cl = skip_tk(cl);
	int fd[2];//
	pipe(fd);
	if (c->pipe[W_PIPE] >= 0)
		close(fd[W_PIPE]);
	else
		c->pipe[W_PIPE] = fd[W_PIPE];
	c->pipe[NEXT_PIPE] = fd[R_PIPE];
	r = cmdlist(c, "", ncl, ll);
	*ncl = cl;
	return (r);
}
char	**cmdlist7(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	cl = skip_tk(cl);
	c->n_type = CONTINUE;
	r = cmdlist(c, "", ncl, ll);
	*ncl = cl;
	return (r);
}
char	**cmdlist8(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	cl = skip_tk(cl);
	r = cmdlist(c, "", ncl, ll);
	if (c->n_type != SKIP)
		c->n_type = OR;
	*ncl = cl;
	return (r);
}
char	**cmdlist9(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

		cl = skip_tk(cl);
		r = cmdlist(c, "", ncl, ll);
		if (c->n_type != SKIP)
			c->n_type = AND;
		*ncl = cl;
	return (r);
}
char	**cmdlist0(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	s = tk_std(cl, 0);
	cl = skip_tk(cl);
	if (!s)
		return (NULL);
	r = cmdlist(c, cl, ncl, ll + 1);
	if (!r)
	{
		free(s);
		return (NULL);
	}
	r[ll] = s;
	return (r);
}
