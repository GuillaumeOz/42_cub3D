/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_2d_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:51:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 17:02:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_crop_rectangle(t_vector2 info[3],
													t_map *map, t_color color)
{
	float i;
	float j;
	float range;

	i = 0;
	range = (map->resolution.x * 0.07);
	if (range > map->resolution.y * 0.07)
		range = map->resolution.y * 0.07;
	while (i < info[1].x)
	{
		j = 0;
		while (j < info[1].y)
		{
			if (vector2_distance(create_vector2(info[2].x, info[2].y),
					create_vector2(info[0].x + i, info[0].y + j)) < range)
				put_pixel(g_app->image,
					create_vector2(info[0].x + i, info[0].y + j), color);
			j++;
		}
		i++;
	}
}

void		put_square(t_map *map, t_vector2 info[3])
{
	t_vector2	pos;
	t_vector2	draw_info[3];

	pos = create_vector2(map->resolution.x * 0.155, map->resolution.y * 0.83);
	draw_info[0] = info[1];
	draw_info[1] = info[2];
	draw_info[2] = pos;
	if (map->board[(int)info[0].y][(int)(info[0].x)]->type == wall)
		draw_crop_rectangle(draw_info, map, create_color(0, 0, 155, 255));
	else if (map->board[(int)info[0].y][(int)(info[0].x)]->type == sprite)
		draw_crop_rectangle(draw_info, map, create_color(50, 220, 220, 255));
	else if (map->board[(int)info[0].y][(int)(info[0].x)]->type == empty ||
		map->board[(int)info[0].y][(int)(info[0].x)]->type == dead_monster)
		draw_crop_rectangle(draw_info, map, create_color(255, 255, 255, 255));
	else if (map->board[(int)info[0].y][(int)(info[0].x)]->type == door ||
		map->board[(int)info[0].y][(int)info[0].x]->type == closed_door)
		draw_crop_rectangle(draw_info, map, create_color(255, 155, 100, 255));
	else if (map->board[(int)info[0].y][(int)(info[0].x)]->type == monster)
		draw_crop_rectangle(draw_info, map, create_color(150, 75, 150, 255));
	else if (map->board[(int)info[0].y][(int)(info[0].x)]->type == medikit)
		draw_crop_rectangle(draw_info, map, create_color(0, 255, 0, 255));
	else if (map->board[(int)info[0].y][(int)(info[0].x)]->type == secret)
		draw_crop_rectangle(draw_info, map, create_color(255, 153, 0, 255));
}

static void	draw_player_n_forward(t_player *hero, int offset_x, int offset_y)
{
	t_vector2 line[2];

	line[0] = create_vector2(hero->pos.x + offset_x, hero->pos.y + offset_y);
	line[1] = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
		hero->pos.x + offset_x), ((-(int)(hero->size) + 1) * sin(hero->pitch) +
													(hero->pos.y + offset_y)));
	draw_circle(create_vector2(hero->pos.x + offset_x, hero->pos.y + offset_y),
			hero->radius * 2, create_color(255, 50, 50, 255));
	draw_line(line, create_color(0, 0, 0, 255), 2);
}

void		draw_2d_map(t_map *map, t_player *hero)
{
	t_vector2		info[3];
	int				offset_x;
	int				offset_y;

	offset_x = map->resolution.x * 0.155 - hero->pos.x;
	offset_y = map->resolution.y * 0.83 - hero->pos.y;
	info[0] = create_vector2(0, 0);
	info[1] = create_vector2(offset_x, offset_y);
	info[2] = create_vector2(hero->size - 1, hero->size - 1);
	while ((int)info[0].y < map->size.y)
	{
		info[0].x = 0;
		info[1].x = offset_x;
		while ((int)info[0].x < map->size.x)
		{
			put_square(map, info);
			info[1].x = info[1].x + 1 + info[2].x;
			info[0].x++;
		}
		info[1].y = info[1].y + 1 + info[2].y;
		info[0].y++;
	}
	draw_player_n_forward(hero, offset_x, offset_y);
}
