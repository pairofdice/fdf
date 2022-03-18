/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:47:29 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/13 15:43:20 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len >= len)
		return (ft_memcpy(dst, src, len));
	ft_memcpy(dst, src, len);
	ft_memset(dst + src_len, 0, len - src_len);
	return (dst);
}
