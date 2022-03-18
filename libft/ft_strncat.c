/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:44:17 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/13 17:59:02 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	destlen;
	size_t	srclen;
	size_t	atmost;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (srclen < n)
		atmost = srclen;
	else
		atmost = n;
	ft_memcpy(dest + destlen, src, atmost);
	dest[destlen + atmost] = '\0';
	return (dest);
}
