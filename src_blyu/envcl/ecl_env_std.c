#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_env_std(char *cl, size_t B)
{
	char	*envname;
	char	*env;
	size_t	i;
	size_t	ii;
	char	*r;

	envname = extractenv(cl);
	if (!envname)
		return (NULL);
//TESTs(envname)
	i = 0;
	if (*envname)
	{
		cl++;
		env = get_env(envname);
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
		r = ecl_sp(cl + ii, B + i + 1);/*  */
		if (!r || !*r)
		{
			free(envname);
			return (r);
		}
		r[B + i] = ' ';
	}
	else
	{
		r = ecl_std(cl + ii, B + i);/*  */
		if (!r || !*r)
		{
			free(envname);
			return (r);
		}
	}
	if (i)
		memcpy(r + B, env, i);/*  */
	free(envname);
	return (r);
}//25
