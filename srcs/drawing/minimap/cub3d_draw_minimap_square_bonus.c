/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_minimap_square_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:51:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:21:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_minimap_square_pos_bonus(int *x, int *y,
	t_engine *engine, t_player *player)
{
	double	square_pos_x;
	double	square_pos_y;

	square_pos_x = (player->pos.x * 10) - engine->resolution.x / 14;
	square_pos_y = (player->pos.y * 10) - engine->resolution.y / 14;
	*x *= 10;
	*y *= 10;
	*x -= (int)(square_pos_x);
	*y -= (int)(square_pos_y);
}

void	draw_minimap_square_bonus(t_engine *engine, t_color color,
	int x, int y)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	set_minimap_square_pos_bonus(&x, &y, engine, engine->player);
	start_y = y + 1;
	end_x = x + 10;
	end_y = y + 10;
	while (start_y < end_y)
	{
		start_x = x + 1;
		while (start_x < end_x)
		{
			put_minimap_pixel_bonus(engine->app, start_x, start_y, color);
			start_x++;
		}
		start_y++;
	}
}
