#include "minishell2.h"

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

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

int main(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		j;
	char	*up_to_equal;
	char	*copy_str;
	size_t	len;

	i = 1;
	while(argv[i])
	{
		copy_str = ft_strdup(argv[2]);
		up_to_equal = strlcpy__(up_to_equal, argv[i], '=');//　=の前の処理まで
		j = 0;
		while(copy_str[j] != '=')
			j++;
		len = ft_strlen(copy_str);
		tmp = ft_substr(copy_str, j + 1, len -j -1);
		i++;
	}
	printf("%s", tmp);
	return (0);
}
