/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_constructors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:18:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 19:30:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ray	create_ray(void)
{
	t_ray result;

	result.ray = create_vector2(0, 0);
	return (result);
}

t_ray	*malloc_ray(void)
{
	t_ray *result;

	result = (t_ray*)malloc(sizeof(t_ray));
	if (result == NULL)
		catch_error(MALLOC_RAY_1);
	*result = create_ray();
	return (result);
}
