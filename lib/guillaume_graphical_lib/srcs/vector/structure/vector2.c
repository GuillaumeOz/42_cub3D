/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:20:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/24 22:19:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector2	*malloc_vector2(float x, float y)
{
	t_vector2 *vector2;

	vector2 = (t_vector2*)malloc(sizeof(t_vector2));
	if (vector2 == NULL)
		ggl_error("Error 1\n A vector2 can't be malloc");
	*vector2 = create_vector2(x, y);
	return (vector2);
}

t_vector2	create_vector2(float x, float y)
{
	t_vector2 vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

void		destroy_vector2(t_vector2 to_destroy)
{
	(void)to_destroy;
}

void		free_vector2(t_vector2 *to_free)
{
	destroy_vector2(*to_free);
	free(to_free);
}
