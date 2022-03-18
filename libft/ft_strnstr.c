/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:33:37 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/20 16:43:17 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i)
			&& *(needle + i) != '\0' && i < len)
			i++;
		if (*(needle + i) == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
