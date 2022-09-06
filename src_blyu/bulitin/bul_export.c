#include "../minishell.h"

int	bul_export(int argc, char *argv[])
{
	size_t	i;
	size_t	ii;
	int		r;

	r = 0;
	i = 1;
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
			r = ep3("minishell: export: `", argv[i]\
			, "': not a valid identifier\n");
		i++;
	}	
	return (r);
}
