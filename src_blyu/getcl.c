#include "minishell.h"
#include "debug.h"

char	*gcl_std(char	*cl, size_t	B);
char	*gcl_dq(char	*cl, size_t	B);
char	*gcl_sq(char	*cl, size_t	B);
char	*gcl_nc(char	*cl, size_t	B);
extern int	g_;

char	*getcl(void)
{
	char	*cl;
	char	*r;

	g_ = READING;
	cl = readline(PROMPT);
	if (!cl)
	{
		g_ = EXEING;
		return (NULL);
	}
	r = gcl_std(cl, 0);
	free(cl);
	g_ = EXEING;
	return (r);
}

char	*gcl_std(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (!((!i || cl[i - 1] != '\\') && cl[i] == '\\' && cl[i + 1] == '\0') \
	&& cl[i] != '"' \
	&& cl[i] != '\'' \
	&& cl[i] != '|' && strncmp(cl + i, "&&", 2)/*  */ \
		&& cl[i])
		i++;
	if (!cl[i])
	{
//TEST
		r = malloc(B + i + 1);
		if (!r)
			return(m_error());
		r[B + i] = '\0';
	}
	else if (cl[i] == '|' || cl[i] == '&')
	{
//TEST
		r = gcl_nc(cl + i, B + i);
		if (!r)
			return (NULL);
	}
	else if (cl[i] == '\\')
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_std(ncl, B + i);
			free(ncl);
			if (!r)
				return (NULL);
		}
	}
	else if (cl[i] == '"')
	{
//TEST
		r = gcl_dq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	else //(cl[i] == '\'')
	{
//TEST
		r = gcl_sq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25

char	*gcl_dq(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (cl[i] != '"' && cl[i])
		i++;
	if (!cl[i])
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_dq(ncl, B + i + 1);
			free(ncl);
			if (!r)
				return (NULL);
			r[B + i] = '\n';
		}
	}
	else //(cl[i] == '"')
	{
		r = gcl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25

char	*gcl_sq(char *cl, size_t B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (cl[i] != '\'' && cl[i])
		i++;
	if (!cl[i])
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_sq(ncl, B + i + 1);
			free(ncl);
			if (!r)
				return (NULL);
			r[B + i] = '\n';
		}
	}
	else //(cl[i] == '\'')
	{
		r = gcl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25

char	*gcl_nc(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;
	int		e;

	i = 0;
	e = 1;
	while ((cl[i] == '|' || cl[i] == '&') && i < 2)
		i++;
	while (cl[i] && (cl[i] == ' ' || cl[i] == '|' || !strncmp(cl + i, "&&", 2)))
	{
		if (cl[i] == '|' || cl[i] == '&')
		{
			e = 0;
			while (cl[i])
				i++;
		}
		else
			i++;
	}
	if (!cl[i] && e)
	{
//TEST
		ncl = readline(PROMPT_);
		if (!ncl)
			r = gcl_std("", B + i);
		else
		{
			r = gcl_nc(ncl, B + i);
			free(ncl);
			if (!r)
				return (NULL);
		}
	}
	else
	{
		r = gcl_std(cl + i, B + i);
		if (!r)
			return (NULL);
	}
	memcpy(r + B, cl, i);/*  */
	return (r);
}//25

/* 
int main(void)
{
    char *cl;
    t_cmd    *cmd;
	
	signal(SIGINT, sigint_handler);
    cl = getcl();
    while (cl)
    {
        add_history(cl);
		cl = etcl(cl);
		printf("-%s[\\n]\n", cl);
		free(cl);
        cl = getcl();
    }
    return 0;
}
 */