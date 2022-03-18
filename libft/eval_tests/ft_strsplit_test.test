#include <stdio.h>
int ft_wordcounttest(char const *s, char c, int wordcount)
{
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			wordcount++;
			s++;
		}
		while (*s != c && *s)
			s++;
	}
	return (wordcount);
}
void ft_strsplit_test(void)
{
	int n;
	char str[] = "*did**i**************a";

	n = 0;
	printf("%d", ft_wordcounttest(str, '*', n));

}
