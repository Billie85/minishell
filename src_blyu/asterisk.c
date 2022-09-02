#include "minishell.h"
#include "debug.h"

char	*as_std(char *cl, size_t B);
char	*as_as_std(char *cl, size_t B);
char	*as_as_q(char *cl, size_t B, char c);

char	*asterisk(char *cl)
{
	char *r;

	r = as_std(cl, 0);
	free(cl);
	return (r);
}

char	*as_std(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] && cl[i] != '*' && cl[i] != ' ')
	{
		if ( cl[i] == '"')
		{
			i++;
			while (cl[i] != '"')
				i++;
			i++;			
		}
		else if ( cl[i] == '\'')
		{
			i++;
			while (cl[i] != '\'')
				i++;
			i++;			
		}
		else if ( cl[i] == '\\')
			i += 2;
		else
			i++;
	}
	if(!cl[i])
	{
		r = malloc(B + i + 1);
		if (!r)
		{
			printf("malloc error\n");
			return (NULL);
		}
		r[B + i] = '\0';
		memcpy(r + B, cl, i);/*  */
	}
	else if (cl[i] == ' ')
	{
		while (cl[i] == ' ')
			i++;
		r = as_std(cl + i, B + i);
		if (!r)
			return (NULL);
		memcpy(r + B, cl, i);/*  */
	}
	else //(cl[i] == '*')
	{
		char	*s;
		char	**l;
		size_t	ii;
		size_t	xi;

		s = as_as_std(cl, 0);
		if (!s)
			return (NULL);
		l = find(s);
		if (!l)
		{
			free(s);
			return (NULL);
		}
		ii = 0;
		xi = 0;
		while (l[xi])
		{
			ii += i + strlen(l[xi]) + 1;/*  */
			xi++;
		}
		r = as_std(skip_tk(cl), B + ii);
		if (!r)
		{
			free(s);
			free_list(l);
			return (NULL);
		}
		ii = 0;
		xi = 0;
		while (l[xi])
		{
			memcpy(r + B + ii, cl, i);/*  */
			ii += i;
			memcpy(r + B + ii, l[xi], strlen(l[xi]));/*  */
			ii += strlen(l[xi]);/*  */
			r[B + ii] = ' ';
			ii++;
			xi++;
		}
		free(s);
		free_list(l);
		return(r);
	}
	return (r);
}


char	*as_as_std(char *cl, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != '*' && cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'')
		i++;
	if (cl[i] == '*')
	{
		r = malloc(B + i +1);
		if (!r)
			return(NULL);
		r[B + i] = '\0';
	}
	else if (cl[i] == '\\')
	{
		r = as_as_std(cl + i + 2, B + i + 1);
		if (!r)
			return(NULL);
		r[B + i] = cl[i + 1];
	}
	else //	(cl[i] == '"' && cl[i] == '\'')
	{
		r = as_as_q(cl + i + 1, B + i, cl[i]);
		if (!r)
			return(NULL);
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);		
}

char	*as_as_q(char *cl, size_t B, char c)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != c)
		i++;
	r = as_as_std(cl + i + 1, B + i);
	if (!r)
		return(NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}
