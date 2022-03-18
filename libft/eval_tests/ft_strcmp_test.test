/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:25:02 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/15 19:54:59 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
#include <string.h>

int main(void)
{
	printf("REF:    %d\n", strcmp("Hello", "Hello"));
	printf("tested: %d\n", ft_strcmp("Hello", "Hello"));
	printf("REF:    %d\n", strcmp("Hello", "Hell"));
	printf("tested: %d\n", ft_strcmp("Hello", "Hell"));
	printf("REF:    %d\n", strcmp("Hello", "Hella"));
	printf("tested: %d\n", ft_strcmp("Hello", "Hella"));
	printf("REF:    %d\n", strcmp("Hello", "Hellz"));
	printf("tested: %d\n", ft_strcmp("Hello", "Hellz"));
	printf("REF:    %d\n", strcmp("Hello", "Hel"));
	printf("tested: %d\n", ft_strcmp("Hello", "Hel"));
	printf("REF:    %d\n", strcmp("a", "d"));
	printf("tested: %d\n", ft_strcmp("a", "d"));
	char testa[] = "abcd";
	char testb[] = "ABCD";
	printf("REF:    %d\n", strcmp(testa, testb));


}
