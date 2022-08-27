#include "minishell.h"
#include "debug.h"
//構文に問題がある場合は"\0"返す/* 未完 */
char	*ecl_std(char *cl, size_t B);
char	*ecl_dq(char *cl, size_t B);
char	*ecl_sq(char *cl, size_t B);
char	*ecl_sp(char *cl, size_t B);
char	*ecl_env_std(char *cl, size_t B);/* 未完 */
char	*ecl_env_dq(char *cl, size_t B);/* 未完 */
char	*extractenv(char *cl);


char *etcl(char *cl)
{
	char *r;

	r = ecl_std(cl, 0);
	free(cl);
	return (r);
}


char	*ecl_std(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;
//TEST
	i = 0;
	while (*cl == ' ' && *cl)
		cl++;
	while (cl[i] != ' ' && cl[i] != '<' && cl[i] != '>' && cl[i] != '|' && cl[i] != ';' && strncmp(cl + i, "&&", 2)/*  */ \
	&& cl[i] != '$' \
	&& cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' \
	&& cl[i])
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
	else if (cl[i] == ' ' || cl[i] == '<' || cl[i] == '>' || cl[i] == '|' || cl[i] == ';' || cl[i] == '&')
	{
		r = ecl_sp(cl + i, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = ' ';
	}
	else if (cl[i] == '$')
	{
		r = ecl_env_std(cl + i, B + i);
		if (!r)
			return (NULL);		
	}
	else if (cl[i] == '\\')
	{
		i += 2;
		r = ecl_std(cl + i, B + i);
		if (!r)
			return (NULL);		
	}
	else if (cl[i] == '"')
	{
		r = ecl_dq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	else //(cl[i] == '\'')
	{
		r = ecl_sq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_sp(char *cl, size_t B)
{
	size_t	i;
	char	*r;
//TEST
	i = 0;
	if (*cl == ' ')
	{
		while (*cl == ' ' && *cl)
			cl++;
		r = ecl_std(cl, B);
		if (!r)
			return(NULL);
	}
	else if (!strncmp(cl, ">>", 2) || !strncmp(cl, "<<", 2) || !strncmp(cl, "||", 2) || !strncmp(cl, "&&", 2))/*  */
	{
		i = 2;
		r = ecl_std(cl + i, B + i + 1);
		if (!r)
			return(NULL);
		r[B + i] = ' ';
	}
	else //(*cl == '>' || *cl == '<' || *cl == '|' || *cl == ';')
	{
		i = 1;
		r = ecl_std(cl + i, B + i + 1);
		if (!r)
			return(NULL);
		r[B + i] = ' ';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_dq(char	*cl, size_t	B)
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
		r = ecl_env_dq(cl + i, B + i);
		if (!r)
			return (NULL);
	}
	else //(cl[i] == '"')
	{
		r = ecl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_sq(char	*cl, size_t	B)
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
		r = ecl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*ecl_env_std(char *cl, size_t B)
{
	char	*envname;
	char	*env;
	size_t	i;
	size_t	ii;
	char	*r;
//TEST
	envname = extractenv(cl);
	if (!envname)
		return (NULL);
//TESTs(envname)
	if (*envname)
		cl++;
	env = getenv(envname);
//TESTs(env)
	if (env)
		i = strlen(env);/*  */
	else
		i = 0;
	ii = strlen(envname);/*  */
//TESTs(cl)
//TESTn(i)
	if (cl[ii] == ' ' || cl[ii] == '<' || cl[ii] == '>' || cl[ii] == '|' || cl[ii] == ';' || !strncmp(cl + ii, "&&", 2))
	{
		r = ecl_sp(cl + ii, B + i + 1);/*  */
		if (!r)
		{
			free(envname);
			return (NULL);
		}
		r[B + i] = ' ';
	}
	else
	{
		r = ecl_std(cl + ii, B + i);/*  */
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

char	*ecl_env_dq(char *cl, size_t B)
{
	char	*envname;
	char	*env;
	size_t	i;
	char	*r;
//TEST
	envname = extractenv(cl);
	if (!envname)
		return (NULL);
	if (*envname)
		cl++;
//TESTs(envname)
	env = getenv(envname);
//TESTs(env)
	if (env)
		i = strlen(env);/*  */
	else
		i = 0;
	r = ecl_dq(cl + strlen(envname), B + i);/*  */
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