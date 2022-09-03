
#include <stdio.h>
#include <string.h>

//文字列s1と文字列s2を比較します
/* s1 > s2 で正の値、
s1 < s2 で負の値、
s1 = s2で 0 を返す。この大小関係は一般に文字コード順による。 */

 int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
	return (0);
	while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int main(void)
{
    char str[] = "ABC";
    char str1[] = "ABC";
    char str2[] = "ABD";
    char str3[] = "B";
    char str4[] = "AAAA";

    printf("strcmp(%s, %s) = %d\n", str, str1, strcmp(str, str1));
	printf("strcmp(%s, %s) = %d\n", str, str1, ft_strcmp(str, str1));

    printf("strcmp(%s, %s) = %d\n", str, str2, strcmp(str, str2));
    printf("strcmp(%s, %s) = %d\n", str, str2, ft_strcmp(str, str2));

    printf("strcmp(%s, %s) = %d\n", str, str3, strcmp(str, str3));
    printf("strcmp(%s, %s) = %d\n", str, str3, ft_strcmp(str, str3));

    printf("strcmp(%s, %s) = %d\n", str, str4, strcmp(str, str4));
    printf("strcmp(%s, %s) = %d\n", str, str4, ft_strcmp(str, str4));


    return 0;
}