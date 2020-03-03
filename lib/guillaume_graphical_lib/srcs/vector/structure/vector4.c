/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:17:43 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/24 22:21:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector4	*malloc_vector4(float x, float y, float z, float w)
{
	t_vector4	*vector4;
	
	vector4 = (t_vector4*)malloc(sizeof(t_vector4));
	if (vector4 == NULL)
		ggl_error("Error 1\n A vector4 can't be malloc");
	*vector4 = create_vector4(x, y, z, w);
	return (vector4);
}

t_vector4	create_vector4(float x, float y, float z, float w)
{
	t_vector4	vector4;
	
	vector4.x = x;
	vector4.y = y;
	vector4.z = z;
	vector4.w = w;
	return (vector4);
}

void		destroy_vector4(t_vector4 to_destroy)
{
	(void)to_destroy;
}

void		free_vector4(t_vector4 *to_free)
{
	destroy_vector4(*to_free);
	free(to_free);
}
