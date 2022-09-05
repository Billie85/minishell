#include <stddef.h>
//#include "debug.h"

size_t	count_long(char const *s);

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	i1;
	size_t	i2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i1 = count_long(s1);
	i2 = count_long(s2);
	s = malloc(i1 + i2 + 1);
	if (s == NULL)
		return (NULL);
	i1 = 0;
	while (*(s1 + i1))
	{
		*(s + i1) = *(s1 + i1);
		i1++;
	}
	i2 = 0;
	while (*(s2 + i2))
	{
		*(s + i1 + i2) = *(s2 + i2);
		i2++;
	}
	*(s + i1 + i2) = 0;
	return (s);
}

size_t	count_long(char const *s)
{
	size_t	t;

	t = 0;
	while (*(s + t))
		t++;
	return (t);
}
