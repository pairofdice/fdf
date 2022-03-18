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


int memset_1(char c, int n)
{
	void	*memREF;
	void	*memME;

	if (!(memREF = malloc(sizeof(*memREF) * 15)))
		return (0);
	memset(memREF, 'j', 15);

	if (!(memME = malloc(sizeof(*memME) * 15)))
		return (0);
	memset(memME, 'j', 15);

	if ( memcmp(memset(memREF, c, n), ft_memset(memME, c, n), 15) == 0)
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, 0}; */
void ft_memset_test(void)
{
	int i = 0;
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return ;
	memset(mem, 'j', 15);

	char test_A[] = {
		'c',
		'c',
		'\n',
		'\0',
		0
	};

	size_t ints[] = {5, 14, 6, 1};

	printf("ft_memset: \t");
	while (test_A[i] != 0)
	{

		if (memset_1(test_A[i], ints[i]) != 0)
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
