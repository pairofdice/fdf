#include "../libft.h"
#include "libft_test.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../libft.h"
#include "ft_colors.h"
#include <stdlib.h>

void tolower_1()
{
	int i = -128;

	while (i < 128 )
	{
		if (tolower(i) != ft_tolower(i))
		{
			printf(BHRED "\n\t\t--fail--" reset);
			printf("\ninput:   \t%c", (char) i);
			printf("\ntolower:    \t%c", tolower((i)));
			printf("\nft_tolower: \t%c\n\t\t", ft_tolower(i));
			return ;
		}
		i++;
	}
	printf(BHGRN "[OK]" reset);
}
/*
void tolower_2()
{

	if (tolower(0) != ft_tolower(0))
		{
			printf(BHRED "\n\t\t--fail--" reset);
			printf("\ninput:   \t%s", "NULL");
			printf("\ntolower:    \t%c", tolower((0)));
			printf("\nft_tolower: \t%c\n\t\t", ft_tolower(0));
			return ;
		}
	
	printf(BHGRN "[OK]" reset);
}
*/
void ft_tolower_test(void)
{
	int i = 0;

	void (*funs[])() = {tolower_1, 0};
	
	printf("ft_tolower: \t");
	while (funs[i] != 0)
	{
		funs[i]();
		i++;
	}
	
	printf("\n");
}
