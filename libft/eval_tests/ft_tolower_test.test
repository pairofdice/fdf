#include "../libft.h"
#include "libft_test.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../libft.h"
#include "ft_colors.h"
#include <stdlib.h>


void ft_toupper_test(void)
{
	int i = 32;

	//int (*funs[])(char *) = {atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, 0};
	
	printf("ft_toupper: \t");
	while (i < 128)
	{
		
		//if 
			//printf(BHGRN "[OK]" reset);
		if (toupper(i) != ft_toupper(i))
		{
			
			printf(BHRED "\n\t\t--fail--" reset);
			printf("\ninput:   \t%c", (char) i);
			printf("\ntoupper:    \t%c", toupper((i)));
			printf("\nft_toupper: \t%c\n\t\t", ft_toupper(i));
			return ;
		}
		i++;
	}
	printf(BHGRN "[OK]" reset);
	printf("\n");
}
