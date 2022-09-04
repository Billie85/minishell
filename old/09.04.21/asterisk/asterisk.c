#include "../minishell.h"
#include "../debug.h"

char	*as_std(char *cl, size_t B);
char	**as_as_list(char *cl, size_t dw);
char	*as_as_std(char *cl, char **cln, size_t B);
char	*as_as_q(char *cl, char **cln, size_t B, char c);

char	*asterisk(char *cl)
{
	char	*r;

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
		if (cl[i] == '"')
		{
			i++;
			while (cl[i] != '"')
				i++;
			i++;
		}
		else if (cl[i] == '\'')
		{
			i++;
			while (cl[i] != '\'')
				i++;
			i++;
		}
		else if (cl[i] == '\\')
			i += 2;
		else
			i++;
	}
	if (!cl[i])
	{
		r = malloc(B + i + 1);
		if (!r)
			return(m_error());
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
		char	**s;//?
		char	**l;//?
		size_t	ii;//?

		s = as_as_list(cl, 0);
		if (!s)
			return (NULL);
		l = find(s);
		free_list(s);
		if (!l)
			return (NULL);
		i = 0;
		ii = 0;
		while (l[i])
		{
			ii += strlen(l[i]) + 3;/*  */
			i++;
		}
		r = as_std(skip_tk(cl), B + ii);
		if (!r)
		{
			free_list(l);
			return (NULL);
		}
		i = 0;
		ii = 0;
		while (l[i])
		{
			r[B + ii] = '\'';
			ii++;
			memcpy(r + B + ii, l[i], strlen(l[i]));/*  */
			ii += strlen(l[i]);
			memcpy(r + B + ii, "\' ", 2);/*  */
			ii += 2;
			i++;
		}
		free_list(l);
		return (r);
	}
	return (r);
}//25

char	**as_as_list(char *cl, size_t dw)
{
	char	**r;
	char	*s;

	if (*cl == '\0' || *cl == ' ')
	{
		r = malloc((dw + 1) * sizeof(char *));
		if (!r)
			return(m_error());
		r[dw] = NULL;
		return (r);
	}
	else if (*cl == '*' && !dw)
	{
		s = strdup("");/*  */
		if (!s)
			return(m_error());
		while (*cl == '*')
			cl++;
		r = as_as_list(cl, 1);
		if (!r)
		{
			free(s);
			return (NULL);
		}
		r[dw] = s;
		return (r);
	}
	else if (*cl == '*')
	{
		while (*cl == '*')
			cl++;
		if (*cl == '\0')
		{
			s = strdup("");
			if (!s)
				return(m_error());
			r = as_as_list(cl, dw + 1);
			if (!r)
			{
				free(s);
				return (NULL);
			}
			r[dw] = s;
			return (r);
		}
		else
			return (as_as_list(cl, dw));
	}
	else
	{
		s = as_as_std(cl, &cl, 0);
		if (!s)
			return(m_error());
		r = as_as_list(cl, dw + 1);
		if (!r)
		{
			free(s);
			return (NULL);
		}
		r[dw] = s;
		return (r);
	}
}//25

char	*as_as_std(char *cl, char **cln, size_t B)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] && cl[i] != '*' && cl[i] != ' ' && cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'')//line long
		i++;
	if (!cl[i] || cl[i] == '*' || cl[i] == ' ')
	{
		*cln = cl + i;
		r = malloc(B + i +1);
		if (!r)
			return (NULL);
		r[B + i] = '\0';
	}
	else if (cl[i] == '\\')
	{
		r = as_as_std(cl + i + 2, cln, B + i + 1);
		if (!r)
			return (NULL);
		r[B + i] = cl[i + 1];
	}
	else //	(cl[i] == '"' && cl[i] == '\'')
	{
		r = as_as_q(cl + i + 1, cln, B + i, cl[i]);
		if (!r)
			return (NULL);
	}
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}//25

char	*as_as_q(char *cl, char **cln, size_t B, char c)
{
	size_t	i;
	char	*r;

	i = 0;
	while (cl[i] != c)
		i++;
	r = as_as_std(cl + i + 1, cln, B + i);
	if (!r)
		return (NULL);
	if (i)
		memcpy(r + B, cl, i);/*  */
	return (r);
}

/* 
int	main(int argc, char *argv[])
{
	char **s;
	TESTs(argv[1])
	s = as_as_list(argv[1], 0);
	for (size_t i = 0; s[i]; i++)
	{
		printf("%zu\t %s\n", i, s[i]);
	}
	return (0);
} */
