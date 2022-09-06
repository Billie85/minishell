#include "minishell_bonus.h"

char	*gt_std(char *end, size_t B);
char	*gt_mkmem(char *f, size_t B);
char	*gt_std1(char *end, size_t B, char *s, size_t i);
char	*gt_std2(char *end, size_t B, char *s, size_t i);

char	*get_txt(char *end)
{
	return (gt_std(end, 0));
}

char	*gt_std(char *end, size_t B)
{
	char	*s;
	size_t	i;

	s = readline(PROMPT_);
	if (!s)
		return (ft_strdup(""));
	if (!ft_strcmp(s, end))
		return (gt_mkmem(s, B));
	i = ft_strlen(s);
	if (i >= 2 && s[i - 1] != '\\' && s[i] == '\\')
		gt_std1(end, B, s, i);
	else
		gt_std2(end, B, s, i);
	return (NULL);
}

char	*gt_std1(char *end, size_t B, char *s, size_t i)
{
	char	*r;

	i--;
	r = gt_std(end, B + i);
	if (!r || !(*r))
		return (r);
	ft_memcpy(r, s, i);
	return (r);
}

char	*gt_std2(char *end, size_t B, char *s, size_t i)
{
	char	*r;

	r = gt_std(end, B + i + 1);
	if (!r || !(*r))
		return (r);
	r[B + i] = '\n';
	ft_memcpy(r, s, i);
	return (r);
}

char	*gt_mkmem(char *f, size_t B)
{
	char	*r;

	free(f);
	r = malloc(B + 1);
	if (!r)
		return (m_error());
	r[0] = (char)1;
	r[B] = '\0';
	return (r);
}
