#include "minishell.h"
#include "debug.h"
//tk_stdはデフォルト、ファイル名取得のときのみ使う/* 訂正 */
//構文のエラーのときは c->type = SYNTAXERROR を設定/* 訂正 */
char **cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll);

char	*tk_std(char *cl, size_t B);
char	*tk_dq(char *cl, size_t B);
char	*tk_sq(char *cl, size_t B);
char	*tk_ques(char *cl, size_t B, char *(*po)(char *, size_t));
char	*extractenv(char *cl);

extern int exeret;

char    *mkcmd(t_cmd *c, char *cl)
{
	char	*ncl;

	c->cmd = cmdlist(c, cl, &ncl, 0);
	if(!(c->cmd) && c->n_type != SYNTAXERROR)
		return (NULL);
	if (c->n_type == SYNTAXERROR)
		ncl = cl + strlen(cl);
	return (ncl);
}

char **cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	while (*cl == ' ')
		cl++;
	if (!*cl)
	{
//TESTs(cl)
		r = malloc(sizeof(char	**) * ll + 1);
		if (!r)
		{
			free(s);
			printf("malloc error\n");
			return (NULL);
		}
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
		c->pipe[R_PIPE] = open(s, O_RDONLY | O_CREAT, S_IREAD | S_IWRITE);
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
		c->pipe[W_PIPE] = open(s, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);
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
		int fd[2];
		pipe(fd);
		s = get_txt(s);
		if (!s)
			return(NULL);
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
		c->pipe[W_PIPE] = open(s, O_WRONLY | O_CREAT | O_APPEND, S_IREAD | S_IWRITE);
		free(s);
		r = cmdlist(c, cl, ncl, ll);
	}
	else if (!strncmp(cl, "| ", 2))/*  */
	{
//TESTs(cl)
		cl = skip_tk(cl);
		int fd[2];
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
}

char	*tk_std(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' && strncmp(cl + i, "$?", 2) && cl[i] != ' ' && cl[i])
		i++;
	if (!cl[i] || cl[i] == ' ')
	{
//TESTn(B + i)
		r = malloc(B + i + 1);
		if (!r)
		{
			printf("malloc error\n");
			return (NULL);
		}
		r[0] = (char)1;
		r[B + i] = '\0';
	}
	else if (cl[i] == '$')
	{
//TEST
		r = tk_ques(cl + i, B + i, tk_std);
		if (!r)
			return (NULL);		
	}
	else if (cl[i] == '\\')
	{
//TEST
		r = tk_std(cl + i + 2, B + i + 1);
		if (!r)
			return (NULL);	
		r[B + i] = 	cl [B + i + 1];
	}
	else if (cl[i] == '"')
	{
//TEST
		r = tk_dq(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	else //(cl[i] == '\'')
	{
//TEST
		r = tk_sq(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}


char	*tk_dq(char *cl, size_t B)
{
	size_t	i;
	char	*r;

//TEST
	i = 0;
	while (cl[i] != '"' && strncmp(cl + i, "$?", 2))
		i++;
if (cl[i] == '$')
	{
		r = tk_ques(cl + i, B + i, tk_dq);
		if (!r)
			return (NULL);
	}
	else //(cl[i] == '"')
	{
		r = tk_std(cl + i + 1, B + i);
		if (!r)
			return (NULL);
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_sq(char *cl, size_t B)
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	while (cl[i] != '\'')
		i++;
	r = tk_std(cl + i + 1, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_ques(char *cl, size_t B, char *(*f)(char *, size_t))
{
	char	s[32];
	size_t	i;
	char	*r;

TEST
	itosd(s, exeret);
TEST
	i = strlen(s);/*  */
	r = (*f)(cl + 2, B + i);
	if (r)
		memcpy(r + B, s, i);/*  */
	return (r);
}
