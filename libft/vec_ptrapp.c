/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ptrapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:05:58 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/24 15:59:16 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
	Takes an integer and a vector and appends the string onto the vec.
	Checks if sum of lens is larger than reserved memory, if so resizes
	Then just straight memcpy to the end of vec and update len
 */
int	vec_ptrapp(t_vec *vec, void *ptr)
{
	if (!vec || !ptr)
		return (-1);
	if ((vec->len * vec->elem_size) + 1 >= vec->alloc_size)
		if (vec_resize(vec, (vec->len + 1) * 2) == -1)
			return (-1);
	vec->memory[vec->len * vec->elem_size], ptr, sizeof(ptr);
	vec->len += 1;
	return (1);
}
