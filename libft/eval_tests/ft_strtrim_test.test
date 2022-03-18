/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                     :+:      :+:    :+:   */
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


int strtrim_1(char *str, char *strtrimmed)
{
	if (ft_strcmp(ft_strtrim(str), strtrimmed) == 0)
		return (1);
	return (0);
}

void ft_strtrim_test(void)
{
	int i = 0;

	//int (*funs[])(char *) = {strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, strtrim_1, 0};
	char *teststrs[] = {
		""
		, "\v a \v"
		, " a "
		, "a \t\n \t  a"
		, "a\t\n a"
		, 0
	};

	char *teststrstrimmed[] = {
		""
		, "\v a \v"
		, "a"
		, "a \t\n \t  a"
		, "a\t\n a"
		, 0
	};
	printf("ft_strtrim: \t");
	while (teststrs[i] != 0)
	{
		char *str = teststrs[i];
		char *strtrimmed = teststrstrimmed[i];
		if (strtrim_1(str, strtrimmed) != 0)
			printf(BHGRN "[OK]" reset);
		else
		{
			
			printf(BHRED "\t--fail--" reset);
			printf("\ninput:   \t%s", str);
			//printf("\nstrtrim:    \t%s", strtrim(str));
			printf("\nft_strtrim: \t%s\n\t\t", ft_strtrim(str));
		}
		i++;
	}
	printf("\n");
}
