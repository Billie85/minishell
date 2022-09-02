#include "minishell2.h"

size_t	ft_strlen(const char *c);

int main(int argc, char **argv)
{
	size_t str;

	str = ft_strlen(argv[2]);//export->argv[1]
	printf("%ld\n", str);
}