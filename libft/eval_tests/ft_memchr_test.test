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


int memchr_1(char *str, char c, int n)
{
/* 	void	*memREF;
	void	*memME;

	if (!(memREF = malloc(sizeof(*memREF) * 30)))
		return (0);
	memset(memREF, 'j', 30);

	if (!(memME = malloc(sizeof(*memME) * 30)))
		return (0);
	memset(memME, 'j', 30); */


	/* memchr(str, c, n);
	ft_memchr(str, c, n); */
	if ( memcmp(memchr(str, c, n), ft_memchr(str, c, n), ft_strlen(str)) == 0)
		return (1);
	return (0);
}

	/* int (*funs[])(char *) = {atoi_1, atoi_1, 0}; */
void ft_memchr_test(void)
{
	int i = 0;
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return ;
	memset(mem, 'j', 15);

	char *test_A[] = {
		"/|\x12\xff\x09\x42\042\42|\\",
/*
		"/|\x12\xff\x09\x42\2002\42|\\",
		"/|\x12\xff\x09\x42\042\42|\\", 
		"/|\x12\xff\x09\x42\042\42|\\",
		"iawhf\200wf208awfh\xakufi21f4\x42w7fwa1f",
	 	":(){ :|: & };:", 
		*/
		"",
		0
	};

	char test_C[] = { '\x42', '\200', '\x42', '\xde', '\x42', '\xde'};

	size_t ints[] = {10, 10, 2, 10, 30, 16};
	printf("ft_memchr: \t");
	while (test_A[i] != 0)
	{

		if (memchr_1(test_A[i], test_C[i], ints[i]) != 0)
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
