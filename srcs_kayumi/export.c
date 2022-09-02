#include "minishell2.h"

size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalpha(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		get_envp(char *up_to_equal, char *envp[], char *after_equal);

char	*strlcpy__(char *dst, const char *src, char equal)
{
	int	i;
	int	j;

	i = 0;
	while(src[i] != equal)
	i++;
	dst = (char *)malloc(sizeof(char) + i + 1);
	j = 0;
	while (src[j] != equal)
	{	
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

int	main(int argc, char **argv, char *envp[])
{
	char	*after_equal;
	int		i;
	int		j;
	char	*up_to_equal;
	char	*copy_str;
	size_t	len;

	if (ft_memcmp(argv[1], "export", 6) != 0)//exporttttとか通っちゃう。
	{
		printf("It's wrong.");
		exit (EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{
		copy_str = ft_strdup(argv[2]);
		up_to_equal = strlcpy__(up_to_equal, argv[i], '=');
		j = 0;
		while (copy_str[j] != '=')
			j++;
		len = ft_strlen(copy_str);
		after_equal = ft_substr (copy_str, j + 1, len - j - 1);
		free(copy_str);
		get_envp(up_to_equal, envp, after_equal);
		i++;
	}
	printf("export ");
	printf("%s", up_to_equal);
	printf("=");
	printf("%s ", after_equal);
	printf("\n");
	return (0);
}
