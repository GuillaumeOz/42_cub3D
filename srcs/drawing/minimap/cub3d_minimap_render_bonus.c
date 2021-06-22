/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap_render_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:23:21 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:22:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	square_color_selector_bonus(char tile)
{
	t_color	color;

	if (tile == '0')
		color = create_color(220, 220, 230, 255);
	else if (tile == '1')
		color = create_color(45, 70, 140, 255);
	else if (tile == '2')
		color = create_color(155, 130, 30, 255);
	else if (ft_ischar("abcdefghijk", tile))
		minimap_secret_door_color_selector_bonus(&color, tile);
	else
		color = create_color(220, 220, 230, 255);
	return (color);
}

static	void	set_minimap_coord_bonus(t_int_vector2 *start,
	t_int_vector2*end, t_player *player, t_engine *engine)
{
	if (((int)player->pos.x - 10) > 0)
		start->x = (int)player->pos.x - 10;
	else
		start->x = 0;
	if (((int)player->pos.y - 10) > 0)
		start->y = (int)player->pos.y - 10;
	else
		start->y = 0;
	if (((int)player->pos.x + 10) < (int)ft_strlen(list_at(engine->map, 0)))
		end->x = (int)player->pos.x + 10;
	else
		end->x = (int)ft_strlen(list_at(engine->map, 0));
	if (((int)player->pos.y + 10) < (int)engine->map->size)
		end->y = ((int)player->pos.y + 10);
	else
		end->y = (int)engine->map->size;
}

static void	display_minimap_bonus(t_engine *engine, t_player *player)
{
	t_int_vector2	start;
	t_int_vector2	end;
	t_color			color;
	char			*line;
	int				tmp_start_x;

	set_minimap_background_bonus(engine);
	set_minimap_coord_bonus(&start, &end, player, engine);
	tmp_start_x = start.x;
	while (start.y < end.y)
	{
		start.x = tmp_start_x;
		line = (char *)list_at(engine->map, start.y);
		while (start.x < end.x)
		{
			if (line[start.x] != ' ')
			{
				color = square_color_selector_bonus(line[start.x]);
				draw_minimap_square_bonus(engine, color, start.x, start.y);
			}
			start.x++;
		}
		start.y++;
	}
	draw_minimap_player_bonus(engine->app);
}

void	minimap_render_bonus(t_engine *engine, t_player *player)
{
	if (engine->bonus & MINIMAP_BONUS)
		display_minimap_bonus(engine, player);
}
