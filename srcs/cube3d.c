/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/28 20:23:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define FOV 70.0f

/*

|       x
|	   /
|     r
|	 /
|	o
o-----------

|		/|
|    1 / |  y
|     /  |
|	 / alpha
|   x----+
|	   x
o-----------

a = adjacent
o = oppose
h = hypothenuse

SOH/CAH/TOA
sin -> on a o et h / cos -> on a a et h / tan -> on a o a

x = cos(alpha)
y = sin(alpha)

*/

int handle_key(int key, void *param)
{
	static float move_speed = 0.8;
	static float rotation_speed = 10;
	t_player *player;

	player = (t_player*)param;
	if (key == ESC_KEY)
		close_application();
	// if (key == NK4_KEY && move_speed > 1)
	// 	move_speed--;
	// if (key == NK6_KEY && move_speed < 10)
	// 	move_speed++;
	if (key == A_KEY)
		player->pos.x -= move_speed;
	if (key == D_KEY)
		player->pos.x += move_speed;
	if (key == W_KEY)
		player->pos.y -= move_speed;
	if (key == S_KEY)
		player->pos.y += move_speed;
	if (key == LEFT_KEY)
		player->angle -= rotation_speed;
	if (key == RIGHT_KEY)
		player->angle += rotation_speed;
	return (0);
}

t_vector2	get_contact_pos(t_vector2 pos, t_vector2 target)
{
	t_vector2 tmp_pos;
	t_vector2 tmp_target;
	// t_vector2 result;

	tmp_pos = substract_vector2_to_vector2(pos, pos);
	tmp_target = substract_vector2_to_vector2(target, pos);
	return (tmp_pos);
	//return (result);
}

void 		*calc_detection(t_map *map, t_vector2 pos)
{
	int x;
	int y;

	x = (int)(pos.x);
	y = (int)(pos.y);
	if (map->board[x][y]->type == wall)
		return (map->board[x][y]);
	return (NULL);
}

t_vector2	cut_aff_x(t_vector2 player_actual, t_vector2 delta, float angle)
{
	t_vector2 result;
	
	if (delta.x >= 0)
	{
		result.x = ((int)player_actual.x + 1) - player_actual.x;
		result.y = result.x * tan(angle);
	}
	else
	{
		result.x = (int)player_actual.x - player_actual.x;
		result.y = result.x * tan(angle);
	}
	return (result);
}

t_vector2	cut_aff_y(t_vector2 player_actual, t_vector2 delta, float angle)
{
	t_vector2 result;

	if (delta.y >= 0)
	{
		result.y = (int)player_actual.y + 1 - player_actual.y;
		result.x = result.y / tan(angle);
	}
	else
	{
		result.y = (int)player_actual.y - player_actual.y;
		result.x = result.y / tan(angle);
	}
	return (result);
}

float		calc_dist(t_vector2 p1, t_vector2 p2)
{
	float result;

	result = pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
	return (result);
}

t_vector2 cast_ray(t_map *map, t_vector2 actual, float angle)
{
	t_vector2	cut_tab[2];
	t_vector2	delta;
	void		*hit;
	float		radian;

	radian = degree_to_radian(angle);
	delta = create_vector2(cos(radian), sin(radian));
	hit = NULL;
	cut_tab[0] = add_vector2_to_vector2(actual, cut_aff_x(actual, delta, radian));
	cut_tab[1] = add_vector2_to_vector2(actual, cut_aff_y(actual, delta, radian));

	while (hit == NULL)
	{
		// actual = add_vector2_to_vector2(actual, delta);

		if (calc_dist(actual, cut_tab[0]) < calc_dist(actual, cut_tab[1]))
		{
			hit = calc_detection(map, cut_tab[0]);
			if (hit == NULL)
			{
				cut_tab[0].x += (delta.x >= 0) ? 1 : -1;
				cut_tab[0].y += (delta.x >= 0) ? 1 * tan(radian) : -1 * tan(radian);
			}
		}
		else
		{
			hit = calc_detection(map, cut_tab[1]);
			if (hit == NULL)
			{
				cut_tab[1].y += (delta.y >= 0) ? 1 : -1;
				cut_tab[1].x += (delta.y >= 0) ? 1 / tan(radian) : -1 / tan(radian);
			}
		}
	}
	if (calc_dist(actual, cut_tab[0]) < calc_dist(actual, cut_tab[1]))
		return (cut_tab[0]);
	return (cut_tab[1]);
}

void	draw_wall(t_vector2 impact, t_vector2 actual_pos, float actual_angle, int x)
{
	float dist;
	float height;
	
	actual_angle += 1;
	dist = sqrt(calc_dist(actual_pos, impact));

	//h = 40 | d = 3
	height = ((0.40 * g_app->size.y) * 3) / dist;
	draw_rectangle(create_vector2((g_app->size.x - x), (g_app->size.y - height) / 2), create_vector2(1, height), create_color(120, 120, 120, 255));
}

int draw_map(void *param)
{
	t_game_engine *engine;

	engine = (t_game_engine *)(param);// add modification later

	clear_application(create_color(50, 50, 50, 255)); //clear the back ground

	draw_rectangle(create_vector2(0, 0), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->ceiling));//draw the ceiling -> start screen
	draw_rectangle(create_vector2(0, g_app->size.y / 2), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->floor));//draw the floor -> middle screen
/*
a = adjacent
o = oppose
h = hypothenuse

SOH/CAH/TOA
sin -> on a o et h / cos -> on a a et h / tan -> on a o a

x = cos(alpha)
y = sin(alpha)
*/
	t_vector2 impact;
	float angle_begin;
	float angle_delta;
	float fish_eye;
	float angle_actual;
	// float tmp;
	size_t i;

	angle_begin = engine->player->angle + FOV / 2;
	angle_delta = FOV / g_app->size.x;
	fish_eye = (angle_begin + (angle_begin - FOV)) / 2;
	// PRINTF(cos(degree_to_radian((angle_begin - FOV) / 2)));
	// PRINTF(angle_begin);
	// tmp = cos(fish_eye);
	PRINTF(fish_eye);
	i = 0;
	while (i <= g_app->size.x)
	{
		// if (engine->player->angle > 360)
		// 	engine->player->angle = 0;
		// else if (engine->player->angle < 0)
		// 	engine->player->angle = 360;
		angle_actual = angle_begin - angle_delta * i;
		impact = cast_ray(engine->map, engine->player->pos, angle_actual);
		draw_wall(impact, engine->player->pos, angle_actual, i);
		i++;
	}
	render_application();
	return (1);
}

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argv[1], &resolution);
	resize_application((int)resolution.x, (int)resolution.y);

	add_interaction_to_application(KEYPRESS, &handle_key, engine.player);
	render_funct_application(&draw_map, &engine);

	return (run_application());
}
