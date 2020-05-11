/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:20:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/24 22:19:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector3	*malloc_vector3(float x, float y, float z)
{
	t_vector3 *vector3;

	vector3 = (t_vector3*)malloc(sizeof(t_vector3));
	if (vector3 == NULL)
		ggl_error("Error 1\n A vector3 can't be malloc");
	*vector3 = create_vector3(x, y, z);
	return (vector3);
}

t_vector3	create_vector3(float x, float y, float z)
{
	t_vector3 vector3;

	vector3.x = x;
	vector3.y = y;
	vector3.z = z;
	return (vector3);
}

void		destroy_vector3(t_vector3 to_destroy)
{
	(void)to_destroy;
}

void		free_vector3(t_vector3 *to_free)
{
	destroy_vector3(*to_free);
	free(to_free);
}
