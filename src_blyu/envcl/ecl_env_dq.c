#include "../minishell.h"
#include "envcl.h"

#include "../debug.h"

char	*ecl_env_dq1(char *cl, size_t B, char *env, size_t ii);

char	*ecl_env_dq(char *cl, size_t B)
{
	char	*envname;
	char	*env;
	size_t	ii;

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
	free(envname);
	return (ecl_env_dq1(cl, B, env, ii));
}

char	*ecl_env_dq1(char *cl, size_t B, char *env, size_t ii)
{
	size_t	i;
	char	*r;

	if (env)
		i = strlen(env);/*  */
	else
		i = 0;
	r = ecl_dq(cl + ii, B + i);/*  */
	if (!r || !*r)
		return (r);
	if (i)
		memcpy(r + B, env, i);/*  */
	return (r);
}