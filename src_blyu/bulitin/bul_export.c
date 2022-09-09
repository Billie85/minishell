#include "../minishell.h"

int	one_arg(void);

int	bul_export(int argc, char *argv[])
{
	size_t	i;
	size_t	ii;
	int		r;

	r = 0;
	i = 1;
	if (argc == 1)
		return (one_arg());
	while ((int)i < argc)
	{
		ii = 0;
		while (ft_isalpha(argv[i][ii]))
			ii++;
		if (argv[i][ii] == '=')
		{
			argv[i][ii] = '\0';
			set_env(argv[i], argv[i] + ii + 1);
		}
		else if (argv[i][ii] != '\0')
			r = ep3("minishell: export: `", argv[i] \
			, "': not a valid identifier\n");
		i++;
	}
	return (r);
}

int	one_arg(void)
{
	char	**export;

	export = ev(NULL);
	if (!export)
		return (1);
	while (*export)
	{
		printf("declare -x %s\n", *export);
		export++;
	}
	return (0);
}
