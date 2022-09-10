#include "../minishell_bonus.h"

int	is_opn(char *s);

int	bul_echo(int argc, char *argv[])
{
	size_t	i;
	int		nop;

	if (argc == 1)
		return (printf("\n") * 0);
	i = 1;
	nop = 0;
	while (argv[i] && is_opn(argv[i]))
	{
		nop = 1;
		i++;
	}
	while ((int)i < argc)
	{
		printf("%s", argv[i]);
		i++;
		if ((int)i < argc)
			printf(" ");
	}
	if (!nop)
		printf("\n");
	return (0);
}

int	is_opn(char *s)
{
	if (ft_strncmp(s, "-n", 2))
		return (0);
	s++;
	while (*s == 'n')
		s++;
	if (!(*s))
		return (1);
	return (0);
}
