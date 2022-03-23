/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_strapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:05:58 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/17 19:08:40 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
	Takes a string and a vector and appends the string onto the vec.
	Checks if sum of lens is larger than reserved memory, if so resizes
	Then just straight memcpy to the end of vec and update len
 */
int	vec_strapp(t_vec *vec, char *str)
{
	ssize_t	len;

	if (!vec || !str)
		return (-1);
	len = ft_strlen(str);
	if ((vec->len * vec->elem_size) + len >= vec->alloc_size)
		if (vec_resize(vec, (vec->len + len) * 2) == -1)
			return (-1);
	ft_memcpy(&vec->memory[vec->len * vec->elem_size], str, len);
	vec->len += len;
	return (1);
}
