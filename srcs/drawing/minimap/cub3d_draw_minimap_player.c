/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_minimap_player.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:02:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:23:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_player_bonus(t_application *app)
{
	t_color	color;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;

	color = create_color(50, 170, 75, 255);
	start_x = ((app->resolution.x / 14)) - 10;
	start_y = ((app->resolution.y / 14)) - 10;
	end_x = ((app->resolution.x / 14)) + 10;
	end_y = ((app->resolution.y / 14)) + 10;
	while (start_y < end_y)
	{
		start_x = ((app->resolution.x / 14)) - 10;
		while (start_x < end_x)
		{
			if (sqrtf(powf((((app->resolution.x / 14)) - start_x), 2)
					+ powf((((app->resolution.y / 14)) - start_y), 2))
				- 5.0f <= 0)
				put_minimap_pixel_bonus(app, start_x, start_y, color);
			start_x++;
		}
		start_y++;
	}
}
