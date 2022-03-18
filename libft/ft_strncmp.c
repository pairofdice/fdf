/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:17:44 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/20 16:42:09 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*a && *b && (*a == *b) && i < n)
	{
		a++;
		b++;
		i++;
	}
	if (i == n)
		return (0);
	return (((unsigned char)*a) - ((unsigned char)*b));
}
