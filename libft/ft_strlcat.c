/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:16:22 by jsaarine          #+#    #+#             */
/*   Updated: 2021/12/06 16:47:16 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	int		atmost;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (srclen == 0)
		return (destlen);
	if (destlen > dstsize)
		return (srclen + dstsize);
	atmost = dstsize - destlen - 1;
	if (atmost < 0)
		return (destlen + srclen);
	ft_strncpy(dest + destlen, src, (size_t)atmost);
	dest[destlen + (size_t)atmost] = '\0';
	return (destlen + srclen);
}
