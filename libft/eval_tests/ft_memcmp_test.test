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


int memcmp_1(char *str, char *strB, int n)
{
/* 	void	*memREF;
	void	*memME;

	if (!(memREF = malloc(sizeof(*memREF) * 30)))
		return (0);
	memset(memREF, 'j', 30);

	if (!(memME = malloc(sizeof(*memME) * 30)))
		return (0);
	memset(memME, 'j', 30);
 */
/* 
	memcpy(str, strB, n);
	ft_memcmp(str, strB, n); 
*/
	if ( memcmp(str, strB, n) ==  ft_memcmp(str, strB, n))
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, 0}; */
void ft_memcmp_test(void)
{
	int i = 0;
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return ;
	memset(mem, 'j', 15);

	char *test_A[] = {
		"salut",
		"t\200",
		"testss",
		"test",
		"",
		"test",
		"abcdefghij",
		"abc\0defgh",
		"zyxbcdefgh",
		0
	};

		char *test_B[] = {
		"salut",
		"t\0",
		"test",
		"tEst",
		"test",
		"",
		"abcdefgxyz",
		"abc\0eefgh",
		"abcdefgxyz",
		0
	};

	size_t ints[] = {5, 2, 5, 4, 4, 7, 6, 6, 0};

	printf("ft_memcmp: \t");
	while (test_A[i] != 0)
	{

		if (memcmp_1(test_A[i], test_B[i], ints[i]) != 0)
			printf("💚");
		else
		{
			
			printf("💔");
			/* printf("\ninput:   \t%s %s %zu", test_A[i], ints[i]);
			printf("\nmemset:    \t%d", memset(mem, test_A[i], ints[i]));
			printf("\nft_memset: \t%d\n\t\t", ft_memset(mem, test_A[i], ints[i])); */
		}
		i++;
	}
	printf("\n");
}
