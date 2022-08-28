#include "minishell.h"
#include "debug.h"
char	*tk_std(char *cl, char **ncl, size_t B);
char	*tk_dq(char *cl, char **ncl, size_t B);
char	*tk_sq(char *cl, char **ncl, size_t B);
char	*tk_sp(char *cl, char **ncl, size_t B);
char	*tk_env(char *cl, char **ncl, size_t B);
char	*extractenv(char *cl);

extern int exeret;

char    *mkcmd(t_cmd *c, char *cl, int *pipe)
{
	char	*ncl;
	
	c->cmd = cmdlist(cl, pipe, &ncl, 0);
	if(c->cmd)
		return (NULL);
	return (ncl);
}

char **cmdlist(char *cl, int *pipe, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	s = tk_std(cl, ncl, 0);
	if (!s)
		return (NULL);
	else if (!*s)
	{
		//malloc->null->free(s);->return;
	}
	else if (!strcmp(s, "<"))/*  */
	{}
	else if (!strcmp(s, ">"))/*  */
	{}
	else if (!strcmp(s, "<<"))/*  */
	{}
	else if (!strcmp(s, ">>"))/*  */
	{}
	else if (!strcmp(s, "|"))/*  */
	{}
	else if (!strcmp(s, ";"))/*  */
	{}
	else if (!strcmp(s, "||"))/*  */
	{}
	else if (!strcmp(s, "&&"))/*  */
	{}
	else
	{
		//自分を呼ぶ
	}
}

char	*tk_std(char *cl, char **ncl, size_t B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (*cl == ' ' && *cl)
		cl++;
	while (cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' && cl[i] != '$' && cl[i] == ' ' && cl[i])
		i++;
	if (!cl[i])
	{
		r = malloc(B + i + 1);
		if (!r)
		{
			printf("malloc error\n");
			return (NULL);
		}
		r[B + i] = '\0';
	}
	else if ((cl[i] == ' ' || cl[i] == '<' || cl[i] == '>' || cl[i] == '|' || cl[i] == ';' || cl[i] == '&'))
	{
		r = tk_sp(cl + i, ncl, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = ' ';
	}
	else if (cl[i] == '$')
	{
		r = tk_env(cl + i, ncl, B + i);
		if (!r)
			return (NULL);		
	}
	else if (cl[i] == '\\')
	{
		i += 2;
		r = tk_std(cl + i, ncl, B + i);
		if (!r)
			return (NULL);		
	}
	else if (cl[i] == '"')
	{
		r = tk_dq(cl + i + 1, ncl, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	else //(cl[i] == '\'')
	{
		r = tk_sq(cl + i + 1, ncl, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_sp(char *cl, char **ncl, size_t B)
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	if (*cl == ' ')
	{
		while (*cl == ' ' && *cl)
			cl++;
		r = tk_std(cl, ncl, B);
		if (!r)
			return(NULL);
	}
	else if (!strncmp(cl, ">>", 2) || !strncmp(cl, "<<", 2) || !strncmp(cl, "||", 2) || !strncmp(cl, "&&", 2))/*  */
	{
		i = 2;
		r = tk_std(cl + i, ncl, B + i + 1);
		if (!r)
			return(NULL);
		r[B + i] = ' ';
	}
	else //(*cl == '>' || *cl == '<' || *cl == '|' || *cl == ';')
	{
		i = 1;
		r = tk_std(cl + i, ncl, B + i + 1);
		if (!r)
			return(NULL);
		r[B + i] = ' ';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_dq(char *cl, char **ncl, size_t B)
{
	size_t	i;
	char	*ncl;
	char	*r;

//TEST
	i = 0;
	while (cl[i] != '"' && cl[i] != '$' && cl[i])
		i++;
	if (!cl[i])
	{//構文エラー
		r = malloc(1);
		if (r)
			*r = '\0';
		return (r);
	}
	else if (cl[i] == '$')
	{
		r = tk_env(cl + i, ncl, B + i);
		if (!r)
			return (NULL);
	}
	else //(cl[i] == '"')
	{
		r = tk_std(cl + i + 1, ncl, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_sq(char *cl, char **ncl, size_t B)
{
	size_t	i;
	char	*ncl;
	char	*r;
//TEST
	i = 0;
	while (cl[i] != '\'' && cl[i])
		i++;
	if (!cl[i])
	{//構文エラー
		r = malloc(1);
		if (r)
			*r = '\0';
		return (r);
	}
	else //(cl[i] == '\'')
	{
		r = tk_std(cl + i + 1, ncl, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*tk_env(char *cl, char **ncl, size_t B)
{
	char	*envname;
	char	*env;
	size_t	i;
	size_t	ii;
	char	*r;
//TESTs(cl)
	envname = extractenv(cl);
	if (!envname)
		return (NULL);
//TESTs(envname)
	i = 0;
	if (*envname)
	{
		cl++;
		env = getenv(envname);
		ii = strlen(envname);/*  */
	}
	else
	{
		env = "$";
		ii = 1;
	}
//TESTs(env)
	if (env)
		i += strlen(env);/*  */
//TESTs(cl)
//TESTn(i)
	if (cl[ii] == ' ' || cl[ii] == '<' || cl[ii] == '>' || cl[ii] == '|' || cl[ii] == ';' || !strncmp(cl + ii, "&&", 2))
	{
		r = tk_sp(cl + ii, ncl, B + i + 1);/*  */
		if (!r)
		{
			free(envname);
			return (NULL);
		}
		r[B + i] = ' ';
	}
	else
	{
		r = tk_std(cl + ii, ncl, B + i);/*  */
		if (!r)
		{
			free(envname);
			return (NULL);
		}
	}
	if (i)
		memcpy(r + B, env, i);/*  */
	free(envname);
	return (r);
}

char	*extractenv(char *cl)
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	cl++;
	while (cl[i] && isalnum(cl[i]))
		i++;
//TESTn(i)
	r = malloc(i + 1);
	if (!r)
	{
		printf("malloc error\n");
		return (NULL);
	}
	if (i)
		memcpy(r, cl, i);
	r[i] = '\0';
//TEST
	return (r);
}
