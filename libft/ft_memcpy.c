/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:29:53 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 14:09:59 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*d1;

	d1 = dst;
	if (dst == src || n == 0)
		return (d1);
	while (n >= sizeof(long))
	{
		*(long *) d1 = *(const long *) src;
		d1 += sizeof(long);
		src += sizeof(long);
		n -= sizeof(long);
	}
	if (n >= sizeof(int))
	{
		*(int *) d1 = *(const int *) src;
		d1 += sizeof(int);
		src += sizeof(int);
		n -= sizeof(int);
	}
	while (n-- > 0)
		*(char *) d1++ = *(const char *) src++;
	return (dst);
}
