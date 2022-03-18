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


int strchr_1(char *strA, char c)
{
	void	*mem;
/* 	void	*memME;
 */
	if (!(mem = malloc(sizeof(*mem) * 15)))
		return (0);
	memset(mem, 0, 15);
/* 
	if (!(memME = malloc(sizeof(*memME) * 15)))
		return (0);
	memset(memME, 0, 15);
 */
	memset(mem, 'a', 5);
/* 	memset(memME, 'a', 5);
 */
	if (((size_t)strchr(mem, c)) == ((size_t)ft_strchr(mem, c)))
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, 0}; */
void ft_strchr_test(void)
{
	int i = 0;
/* 	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return ;
	memset(mem, 'j', 15);
 */
	char *test_A[] = {
		"lorem",
		"",
		"lorem ipsum",
		"Hello world!\0Sup?",
		0
	};

	char chars[] = {'m', '\0', 'a', '?'};

	printf("ft_strchr: \t");
	while (test_A[i] != 0)
	{

		if (strchr_1(test_A[i], chars[i]) != 0)
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
