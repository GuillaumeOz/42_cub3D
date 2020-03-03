/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:38:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/03 11:39:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_wall(t_vector2 impact, t_vector2 actual_pos, float fish_eye, int x)
{
	float dist;
	float height;
	
	dist = sqrt(calc_dist(actual_pos, impact));
	//h = 40 | d = 3
	height = ((0.40 * g_app->size.y) * 3) / (dist * fish_eye);
	draw_rectangle(create_vector2((g_app->size.x - x), (g_app->size.y - height) / 2), create_vector2(1, height), create_color(120, 120, 120, 255));//add the texture there
}

int draw_map(void *param)
{
    t_game_engine *engine;
    t_vector2 impact;
	float angle_begin;
	float angle_delta;
	float fish_eye;
	float angle_actual;
	size_t i;
    engine = (t_game_engine *)(param);

    clear_application(create_color(50, 50, 50, 255));

	draw_rectangle(create_vector2(0, 0), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->ceiling));
	draw_rectangle(create_vector2(0, g_app->size.y / 2), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->floor));

	angle_begin = engine->player->angle + FOV / 2;
	angle_delta = FOV / g_app->size.x;
	i = 0;
	while (i <= g_app->size.x)
	{
		// if (engine->player->angle > 360)
		// 	engine->player->angle = 0;
		// else if (engine->player->angle < 0)
		// 	engine->player->angle = 360;
		fish_eye = cos(degree_to_radian(angle_delta * i - FOV / 2));
		angle_actual = angle_begin - angle_delta * i;
		impact = cast_ray(engine->map, engine->player->pos, angle_actual);
		draw_wall(impact, engine->player->pos, fish_eye, i);
		i++;
	}
	render_application();
	return (0);
}
