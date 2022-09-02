# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <ctype.h>

//-nが連続で来た場合の処理の対応。while必要かも
//オプション付き -n -> 最後の改行を出力しない

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

int	main(int argc, char *argv[])
{
	size_t	i;
	size_t len;
	size_t delet_last_space;

	i = 0;
	while(argv[i])
		len = i++;
	delet_last_space = len -1;

	i = 1;
	while(i < len + 1)
	{
		ft_putstr_fd(argv[i], 1);
		if (i < len)
			ft_putchar_fd(' ', 1);
		i++;
	}
	return (0);
}