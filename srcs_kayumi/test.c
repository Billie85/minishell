#include "minishell2.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

int main(void)
{
	char* str;

	str = ft_substr("Kimura Ayumi", 7, 5);
	printf("%s\n", str);

	return 0;
}