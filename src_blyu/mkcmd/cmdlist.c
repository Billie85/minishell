#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

char	**cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	while (*cl == ' ')
		cl++;
	if (!*cl)
	{
//TESTs(cl)
		r = malloc(sizeof(char **) * ll + 1);
		if (!r)
			return(free_return(s, m_error()));
		*ncl = cl;
		if (c->n_type != SKIP)
			c->n_type = CONTINUE;
		r[0] = (char *)1;
		r[ll] = NULL;
	}
	else if (!strncmp(cl, "< ", 2))/*  */
	{
//TESTs(cl)
		cl++;
		while (*cl == ' ')
			cl++;
		s = tk_std(cl, 0);
		cl = skip_tk(cl);
//TESTs(cl)
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
		c->pipe[R_PIPE] = open(s, O_RDONLY | O_CREAT, S_IREAD | S_IWRITE);//S_IERITEが定義されていません。
		free(s);
		r = cmdlist(c, cl, ncl, ll);
	}
	else if (!strncmp(cl, "> ", 2))/*  */
	{
//TESTs(cl)
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
		c->pipe[W_PIPE] = open(s, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);//S_IREADが定義されていません。
		free(s);
		r = cmdlist(c, cl, ncl, ll);
	}
	else if (!strncmp(cl, "<< ", 3))/*  */
	{
//TESTs(cl)
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
		write(fd[W_PIPE], s, sizeof(s));
		close(fd[W_PIPE]);
		free(s);
		if (c->pipe[R_PIPE] >= 0)
			close(c->pipe[R_PIPE]);
		c->pipe[R_PIPE] = fd[R_PIPE];
		r = cmdlist(c, cl, ncl, ll);
	}
	else if (!strncmp(cl, ">> ", 3))/*  */
	{
//TESTs(cl)
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
	}
	else if (!strncmp(cl, "| ", 2))/*  */
	{
//TESTs(cl)
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
	}
	else if (!strncmp(cl, "; ", 2))/*  */
	{
//TESTs(cl)
		cl = skip_tk(cl);
		c->n_type = CONTINUE;
		r = cmdlist(c, "", ncl, ll);
		*ncl = cl;
	}
	else if (!strncmp(cl, "|| ", 3))/*  */
	{
//TESTs(cl)
		cl = skip_tk(cl);
		r = cmdlist(c, "", ncl, ll);
		if (c->n_type != SKIP)
			c->n_type = OR;
		*ncl = cl;
	}
	else if (!strncmp(cl, "&& ", 3))/*  */
	{
//TESTs(cl)
		cl = skip_tk(cl);
		r = cmdlist(c, "", ncl, ll);
		if (c->n_type != SKIP)
			c->n_type = AND;
		*ncl = cl;
	}
	else
	{
//TESTs(cl)
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
	}
	return (r);
}//25
