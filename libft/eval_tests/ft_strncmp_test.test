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


int strncmp_1(const char *a, const char *b, size_t n)
{
	if (strncmp(a, b, n) == ft_strncmp(a, b, n))
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, atoi_1, atoi_1, 
				atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, atoi_1, 0}; */
void ft_strncmp_test(void)
{
	int i = 0;

	char *test_A[] = {
		"salut", 
		"test", 
		"testss", 
		"test", 
		"", 
		"test", 
		"abcdefghij", 
		"abcdefgh", 
		"zyxbcdefgh", 
		"abcdefgh", 
		"test\200", 
		NULL,
		0
	};

	char *test_B[] = {
		"salut", 
		"testss", 
		"test", 
		"tEst", 
		"test", 
		"", 
		"abcdefgxyz", 
		"abcdwxyz", 
		"abcdwxyz", 
		"", 
		"test\0", 
		NULL,
		0
	};

	size_t ints[] = {5,7,7,4,4,4,3,4,0,0,6,0};

	printf("ft_strncmp: \t");
	while (test_A[i] != 0)
	{

		if (strncmp_1(test_A[i], test_B[i], ints[i]) != 0)
			printf("💚");
		else
		{
			
			printf("\t\t💔");
			printf("\ninput:   \t%s %s %zu", test_A[i], test_B[i], ints[i]);
			printf("\nstrncmp:    \t%d", strncmp(test_A[i], test_B[i], ints[i]));
			printf("\nft_strncmp: \t%d\n\t\t", ft_strncmp(test_A[i], test_B[i], ints[i]));
		}
		i++;
	}
	printf("\n");
}
