/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:51:12 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:29:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector2_list	calc_circle(t_vector2 center, float radius)
{
	t_vector2_list	result;
	float			i;
	float			j;

	result = create_t_vector2_list(1);
	i = center.x - radius;
	while (i < center.x + radius)
	{
		j = center.y - radius;
		while (j < center.y + radius)
		{
			if (vector2_distance(center,
									create_vector2(i + 0.5, j + 0.5)) <= radius)
				t_vector2_list_push_back(&result, create_vector2(i, j));
			j++;
		}
		i++;
	}
	return (result);
}

void			draw_circle(t_vector2 pos, int radius, t_color color)
{
	draw_circle_in_image(g_app->image, pos, radius, color);
}

void			draw_circle_in_image(t_image *image, t_vector2 center,
	int radius, t_color color)
{
	t_vector2_list	circle;
	size_t			i;

	circle = calc_circle(center, radius);
	i = 0;
	while (i < circle.size)
	{
		put_pixel(image, t_vector2_list_at(&circle, i), color);
		i++;
	}
	destroy_t_vector2_list(circle);
}
