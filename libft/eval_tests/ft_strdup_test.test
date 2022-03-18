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


int strdup_1()
{
	void	*memREF;
	void	*memME;

	if (!(memREF = malloc(sizeof(*memREF) * 30)))
		return (0);
	memset(memREF, 'j', 30);

	if (!(memME = malloc(sizeof(*memME) * 30)))
		return (0);
	memset(memME, 'j', 30);

	char test[] = "lorem ipsum dolor sit \0 amet";


	memREF = strdup(test);
	memME = ft_strdup(test);
	if ( memcmp(memREF, memME, 30) == 0)
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, 0}; */
void ft_strdup_test(void)
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

	size_t ints[] = {14, 0, 11, 1};

	printf("ft_strdup: \t");
	while (test_A[i] != 0)
	{

		if (strdup_1() != 0)
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
