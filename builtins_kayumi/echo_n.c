# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <ctype.h>

//オプション付き -n -> 最後の改行を出力しない
//まだ終わってない
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

int main(int argc, char *argv[])
{
	size_t	i;
	size_t len;

	i = 0;
	while(argv[i])
		len = i++;

	i = 1;
	while(i < len + 1)
	{
		ft_putstr_fd(argv[i], 1);
		ft_putchar_fd(' ', 1);

		i++;
	}
	return (0);
}