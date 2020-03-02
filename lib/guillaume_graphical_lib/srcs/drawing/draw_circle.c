/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:51:12 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/19 13:21:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void draw_circle(t_vector2 pos, int radius, t_color color)
{
	draw_circle_in_image(g_app->image, pos, radius, color);
}

void	draw_circle_in_image(t_image *image, t_vector2 pos, int radius, t_color color)
{
	t_vector2	actual_pos;
	size_t		i;
	size_t		j;

	i = 0;
	pos = create_vector2((actual_pos.x - radius), (actual_pos.y - radius));
	while (i < (pos.x + radius))
	{
		j = 0;
		actual_pos.y = i;
		while (j < (pos.y + radius))
		{
			if (pow(radius, 2) >= (pow(actual_pos.x - pos.x, 2) + pow(actual_pos.y - pos.y, 2)))
			{
				put_pixel(image, actual_pos.x, actual_pos.y, color);
			}
			j++;
			actual_pos.x = j;
		}
	}
}
