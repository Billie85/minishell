#include "../minishell.h"
#include "../debug.h"
//fd=2

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int	bul_unset(int argc, char *argv[])
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
		if (argv[i][ii] == '\0')
		{
			rm_env(argv[i]);
		}
		else
			r = ep3("minishell: unset: `", argv[i], "': not a valid identifier\n");
		i++;
	}	
	return (r);
}
