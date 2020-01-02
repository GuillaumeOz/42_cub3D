/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:20:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 12:20:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_vector	*malloc_vector(int x, int y)
{
	t_vector *vector;

	vector = (t_vector*)malloc(sizeof(t_vector));
	if (vector == NULL)
		return (NULL);
	*vector = create_vector(x, y);
	return (vector);
}

t_vector	create_vector(int x, int y)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

void		destroy_vector(t_vector to_destroy)
{
	(void)to_destroy;
}

void		free_vector(t_vector *to_free)
{
	destroy_vector(*to_free);
	free(to_free);
}
