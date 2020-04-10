/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:51:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/09 15:48:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void draw_rectangle(t_vector2 pos, t_vector2 size, t_color color)
{
	draw_rectangle_in_image(g_app->image, pos, size, color);
}

void draw_rectangle_in_image(t_image *image, t_vector2 pos, t_vector2 size, t_color color)
{
	t_vector2	rect_pos;

	rect_pos = create_vector2(0, 0);
	while (rect_pos.x < (size_t)size.x)
	{
		rect_pos.y = 0;
		while (rect_pos.y < (size_t)size.y)
		{
			put_pixel(image, create_vector2(rect_pos.x + pos.x,
			rect_pos.y + pos.y), color);
			rect_pos.y++;
		}
		rect_pos.x++;
	}
}
