#include "minishell.h"
//readlineが最初NULLのときと途中でNULLのときそれぞれの処理未完

char	*cl_std(char	*cl, size_t	B);
char	*cl_dq(char	*cl, size_t	B);
char	*cl_sq(char	*cl, size_t	B);

char *getcl(void)
{
	char	*cl;
	char	*r;

	cl = readline(PROMPT);
	if (!cl)
		return (NULL);
	r = cl_std(cl, 0);
	free(cl);
	return (r);
}

char	*cl_std(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (!(cl[i] == '\\' && cl[i + 1] == '\0') && cl[i] != '"' && cl[i] != '\'' && cl[i])
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
	else if (cl[i] == '\\')
	{
		ncl = readline(PROMPT_);
		if (!ncl)
		{
			r = malloc(B + i + 1);
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			r[B + i] = '\0';
		}
		else
		{
			r = cl_std(ncl, B + i);
			free(ncl);
			if (!r)
				return(NULL);
		}
	}
	else if (cl[i] == '"')
	{
		r = cl_dq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	else //(cl[i] == '\'')
	{
		r = cl_sq(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

char	*cl_dq(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (cl[i] != '"' && cl[i])
		i++;
	if (!cl[i])
	{
		ncl = readline(PROMPT_);
		if (!ncl)
		{
			r = malloc(B + i + 1);
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			r[B + i] = '\0';
		}
		else
		{
			r = cl_dq(ncl, B + i + 1);
			free(ncl);
			if (!r)
				return (NULL);
			r[B + i] = '\n';
		}
	}
	else //(cl[i] == '"')
	{
		r = cl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '"';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}


char	*cl_sq(char	*cl, size_t	B)
{
	size_t	i;
	char	*ncl;
	char	*r;

	i = 0;
	while (cl[i] != '\'' && cl[i])
		i++;
	if (!cl[i])
	{
		ncl = readline(PROMPT_);

		if (!ncl)
		{
			r = malloc(B + i + 1);
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			r[B + i] = '\0';
		}
		else
		{
			r = cl_sq(ncl, B + i + 1);
			free(ncl);
			if (!r)
				return (NULL);
			r[B + i] = '\n';
		}
	}
	else //(cl[i] == '\'')
	{
		r = cl_std(cl + i + 1, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = '\'';
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}


int main(void)
{
    char *cl;
    t_cmd    *cmd;
	
	signal(SIGINT, sigint_handler);
    cl = getcl();
    while (cl)
    {
        add_history(cl);
		printf("%s[\\n]\n", cl);
		free(cl);
        cl = getcl();
    }
    return 0;
}
