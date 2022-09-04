#include "minishell.h"
char	*gt_std(char *end, size_t   B);

char	*get_txt(char *end)
{
	return (gt_std(end, 0));
}
char	*gt_std(char *end, size_t   B)
{
	char	*s;
	char	*r;
	size_t	i;

	s = readline(PROMPT_);
	if (!s)
		return(strdup(""));
	if (!strcmp(s, end))/*  */
	{
		free(s);
		r = malloc(B + 1);
		if (!r)
		{
			printf("malloc error\n");
			return (NULL);
		}
		r[0] = (char)1;
		r[B] = '\0';
		return (r);
	}
	i = strlen(s);
	if (i >= 2 && s[i - 1] != '\\' && s[i] == '\\')
	{
		i--;
		r = gt_std(end, B + i);
		if (!r || !(*r))
			return (r);
	}
	else
	{
		r = gt_std(end, B + i + 1);
		if (!r || !(*r))
			return (r);
		r[B + i] = '\n';
	}
	memcpy(r, s, i);/*  */
	return (r);
}