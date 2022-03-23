/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:03:52 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/13 21:36:30 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
	appends vector src to dst
*/
int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	space_needed;

	if (!dst || !src || !src->memory)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, 1);
	space_needed = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size < space_needed)
	{
		if (vec_resize(dst, space_needed * 2) == -1)
			return (-1);
	}
	ft_memcpy(
		&dst->memory[dst->len * dst->elem_size],
		src->memory,
		src->len * 1);
	dst->len += src->len;
	vec_free(src);
	return (1);
}
