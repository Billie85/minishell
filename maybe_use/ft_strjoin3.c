#include <stdlib.h>
#include <stddef.h>
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;
	char	*r;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	i3 = ft_strlen(s3);
	r = malloc(i1 + i2 + i3 + 1);
	if (!r)
		return (NULL);
	ft_memcpy(r, s1, i1);
	ft_memcpy(r + i1, s2, i2);
	ft_memcpy(r + i1 + i2, s3, i3);
	r[i1 + i2 + i3] = '\0';
	return (r);
}
