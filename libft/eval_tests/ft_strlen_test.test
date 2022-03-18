/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:16:56 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/07 13:18:13 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "ft_colors.h"
#include <stdlib.h>


int strlen_1(char *str)
{
	if (atoi(str) == ft_atoi(str))
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, atoi_1, atoi_1, 
				atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, 0}; */
void ft_strlen_test(void)
{
	int i = 0;

	char *teststrs[] = {
		""
		,"0"
		,"   \0   "
		," \t\n\v\f\r 0x1234"
		, " \t0\t"
		,"🙈😘🤬😳"
		, NULL
		, 0
	};
	printf("ft_strlen: \t");
	while (teststrs[i] != 0)
	{
		char *str = teststrs[i];
		if (strlen_1(str) != 0)
			printf("💚");
		else
		{
			
			printf("\t\t💔");
			printf("\ninput:   \t%s", str);
			printf("\natoi:    \t%d", atoi(str));
			printf("\nft_atoi: \t%d\n\t\t", ft_atoi(str));
		}
		i++;
	}
	printf("\n");
}
