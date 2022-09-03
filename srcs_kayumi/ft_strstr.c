#include        <stdio.h>
#include        <string.h>

/* 文字列 s1 の先頭から文字列 s2 を探し、
見つかったときにはその位置をポインタで返却し、
見つからなかったときにはNULLを返却します。
なにも存在しない文字列を渡した場合本家はセグフォする */

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		i = 0;
		while (s1[i] == s2[i] && s2[i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char *)s1);
		else
			s1++;
	}
	return (NULL);
}

int     main(void)
{
	char str[] = "42 tokyo programming school";
        char str2[] = "tokyo";

        printf("%s\n",ft_strstr(str, str2));
        printf("%s\n",strstr(str, str2));

    	return (0);
}