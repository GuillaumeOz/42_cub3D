/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_minimap_background_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:17:22 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:17:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_minimap_background_pixel_bonus(t_application *app,
	 int x, int y, t_color color)
{
	t_float_vector2	circle;
	float			radius;
	t_image			*image;
	char			*tmp;

	if (x < 0 || x > app->resolution.x
		|| y < 0 || y > app->resolution.y)
		return ;
	set_minimap_circle_informations_bonus(app, &radius, &circle);
	if (sqrtf(powf((circle.x - x), 2) + powf((circle.y - y), 2)) - radius >= 0
		&& sqrtf(powf((circle.x - x), 2) + powf((circle.y - y), 2))
		- radius <= 1)
		color = create_color(255, 255, 255, 255);
	if (sqrtf(powf((circle.x - x), 2)
			+ powf((circle.y - y), 2)) - radius >= 1)
		return ;
	image = app->image;
	tmp = image->pixels + (y * image->size_line + x
			* (image->bits_per_pixels / 8));
	tmp[RED_COMP] = color.r;
	tmp[GREEN_COMP] = color.g;
	tmp[BLUE_COMP] = color.b;
	tmp[ALPHA_COMP] = color.a;
}

void	set_minimap_background_bonus(t_engine *engine)
{
	t_int_vector2	start;
	t_int_vector2	end;
	t_color			color;
	t_float_vector2	circle;
	float			radius;

	color = create_color(0, 0, 0, 255);
	set_minimap_circle_informations_bonus(engine->app, &radius, &circle);
	start = create_int_vector2(circle.x - radius, circle.y - radius);
	end = create_int_vector2(circle.x + radius + 1, circle.y + radius + 1);
	while (start.y < end.y)
	{
		start.x = circle.x - radius;
		while (start.x < end.x)
		{
			put_minimap_background_pixel_bonus(engine->app,
				start.x, start.y, color);
			start.x++;
		}
		start.y++;
	}
}
