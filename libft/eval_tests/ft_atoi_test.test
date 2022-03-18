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


int atoi_1(char *str)
{
	if (atoi(str) == ft_atoi(str))
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, atoi_1, atoi_1, 
				atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, 0}; */
void ft_atoi_test(void)
{
	int i = 0;

	char *teststrs[] = {
		""
		,"0"
		,"123:4"
		,"0456780"
		,"+0+0"
		,"Hello1234there1234"
		,"--2147483648"
		,"+2147483647"
		,"1234567890000"
		,"++42"
		," \t\n\v\f\r 0x1234"
		, "\t-2147483649acssa"
		, "\t-2147483648aac"
		, "\t\t-4\t\n\v\f\r2"
		, "\t\t-1"
		, "\t\t-0"
		, "\t\t00042"
		, "\t2147-483647"
		, "\b\t21474+83648"
		, "\r\t\t42 42"
		, "\f\t\t 42 "
		, "\t\tone"
		, "\t\t--42"
		, "\t\t+42"
		, "\t\t+-42"
		, "\t\t-+42"
		, " \t a 1234aa"
		, " \t0\t"
		, NULL
		, 0
	};
	printf("ft_atoi: \t");
	while (teststrs[i] != 0)
	{
		char *str = teststrs[i];
		if (atoi_1(str) != 0)
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
