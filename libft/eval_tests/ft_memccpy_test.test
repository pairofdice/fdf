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


int memccpy_1(char *str, char r, int n)
{
	void	*memREF;
	void	*memME;

	if (!(memREF = malloc(sizeof(*memREF) * 30)))
		return (0);
	memset(memREF, 'j', 30);

	if (!(memME = malloc(sizeof(*memME) * 30)))
		return (0);
	memset(memME, 'j', 30);


	memccpy(memREF, str, r, n);
	ft_memccpy(memME, str, r, n);
	if ( memcmp(memREF, memME, 30) == 0)
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, 0}; */
void ft_memccpy_test(void)
{
	int i = 0;
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return ;
	memset(mem, 'j', 15);

	char *test_A[] = {
		"zyxwvutsrqponmlkjihgfedcba",
		"zyxwvutst",
		"zy\0xw\0vu\0\0tsr",
		"",
		0
	};

	char test_C[] = { 'r', 'r', 'a', 'x'};

	size_t ints[] = {20, 3, 26, 20};

	printf("ft_memccpy: \t");
	while (test_A[i] != 0)
	{

		if (memccpy_1(test_A[i], test_C[i], ints[i]) != 0)
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
