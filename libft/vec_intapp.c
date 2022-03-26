/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_intapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:05:58 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/25 23:39:03 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
	Takes an integer and a vector and appends the string onto the vec.
	Checks if sum of lens is larger than reserved memory, if so resizes
	Then just straight memcpy to the end of vec and update len
 */
int	vec_intapp(t_vec *vec, int nb)
{
	if (!vec)
		return (-1);
	if ((vec->len * vec->elem_size) + 1 >= vec->alloc_size)
		if (vec_resize(vec, (vec->len + 1) * 2) == -1)
			return (-1);
	ft_memcpy(&vec->memory[vec->len * vec->elem_size], &nb, sizeof(int));
	vec->len += 1;
	return (1);
}
