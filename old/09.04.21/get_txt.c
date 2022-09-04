#include "minishell.h"
#include "debug.h"

char	*gt_std(char *end, size_t B);
char	*gt_mkmem(char *f, size_t B);

char	*get_txt(char *end)
{
	return (gt_std(end, 0));
}

char	*gt_std(char *end, size_t B)
{
	char	*s;
	char	*r;
	size_t	i;

	s = readline(PROMPT_);
	if (!s)
		return (strdup(""));/*  */
	if (!strcmp(s, end))/*  */
		return(gt_mkmem(s, B));
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
}//25

char	*gt_mkmem(char *f, size_t B)
{
	char	*r;

	free(f);
	r = malloc(B + 1);
	if (!r)
		return(m_error());
	r[0] = (char)1;
	r[B] = '\0';
	return (r);
}
