/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_floor_color_render.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:24:43 by gozsertt          #+#    #+#             */
/*   Updated: 2021/04/28 19:40:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_color_render(t_engine *engine)
{
	t_color	*floor_color;
	int		x;
	int		y;

	floor_color = engine->floor;
	y = engine->resolution.y / 2;
	while (y < engine->resolution.y)
	{
		x = 0;
		while (x < engine->resolution.x)
		{
			set_pixel_to_image(engine->app, x, y, *floor_color);
			x++;
		}
		y++;
	}
}
