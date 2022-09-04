#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_env_dq(char *cl, size_t B)
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
//TESTs(envname)
//TESTs(env)
	if (env)
		i = strlen(env);/*  */
	else
		i = 0;
	r = ecl_dq(cl + ii, B + i);/*  */
	if (!r || !*r)
		return (r);
	if (i)
		memcpy(r + B, env, i);/*  */
	free(envname);
	return (r);
}
