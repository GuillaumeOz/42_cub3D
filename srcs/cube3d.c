/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/25 20:19:56 by gozsertt         ###   ########.fr       */
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

int test_render_app(void *param) // -> void **param
{
	t_color *color;
	t_color *color2;
	t_vector2 *pos;
	t_vector2 *pos2;

	color = ((void **)(param))[0];
	color2 = ((void **)(param))[1];
	pos = ((void **)(param))[2];
	pos2 = ((void **)(param))[3];

	clear_application(create_color(50, 50, 50, 255));

	draw_rectangle(*pos, create_vector2(150, 50), *color);
	draw_rectangle(*pos2, create_vector2(150, 50), *color2);

	render_application();

	return (0);
}

int handle_key(int key, void *param)
{
	static int move_speed = 3;
	t_vector2 *pos;
	t_vector2 *pos2;

	pos = ((void **)(param))[2];
	pos2 = ((void **)(param))[3];

	if (key == ESC_KEY)
		close_application();
	if (key == NK4_KEY && move_speed > 1)
		move_speed--;
	if (key == NK6_KEY && move_speed < 10)
		move_speed++;
	if (key == A_KEY)
		pos->x -= move_speed;
	if (key == D_KEY)
		pos->x += move_speed;
	if (key == W_KEY)
		pos->y -= move_speed;
	if (key == S_KEY)
		pos->y += move_speed;
	if (key == LEFT_KEY)
		pos2->x -= move_speed;
	if (key == RIGHT_KEY)
		pos2->x += move_speed;
	if (key == UP_KEY)
		pos2->y -= move_speed;
	if (key == DOWN_KEY)
		pos2->y += move_speed;
	return (0);
}

t_vector2	get_contact_pos(t_vector2 pos, t_vector2 target)
{
	t_vector2 tmp_pos;
	t_vector2 tmp_target;
	//t_vector2 result;

	tmp_pos = substract_vector2_to_vector2(pos, pos);
	tmp_target = substract_vector2_to_vector2(target, pos);
	return (tmp_pos);
	//return (result);
}

void *calc_detection(t_map *map, t_vector2 pos)
{
	int x;
	int y;

	x = (int)(pos.x);
	y = (int)(pos.y);
	if (map->board[x][y]->type == wall)
		return (map->board[x][y]);
	return (NULL);
}

t_vector2 cast_ray(t_map *map, t_vector2 actual, float angle)
{
	t_vector2 delta;
	void *hit;
	float radian;

	radian = degree_to_radian(angle);
	delta = create_vector2(cos(radian), sin(radian));
	hit = NULL;
	while (	hit == NULL &&
			actual.x >= 0 && actual.x < map->size.x &&
			actual.y >= 0 && actual.y < map->size.y)
	{
		actual = add_vector2_to_vector2(actual, delta);
		hit = calc_detection(map, actual);
	}
	printf("Wall hit at angle %f = %d / %d\n", angle, (int)(actual.x), (int)(actual.y));
	return (actual);
}

int draw_map(void *param)
{
	t_game_engine *engine;

	engine = (t_game_engine *)(param);

	clear_application(create_color(50, 50, 50, 255));

	draw_rectangle(create_vector2(0, 0), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->ceiling));
	draw_rectangle(create_vector2(0, g_app->size.y / 2), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->floor));
	float angle_begin;
	float angle_delta;
	float angle_actual;
	size_t i;

	angle_begin = engine->player->angle + FOV / 2;
	angle_delta = FOV / g_app->size.x;

	printf("---=====---\n");
	i = 0;
	while (i < g_app->size.x)
	{
		angle_actual = angle_begin - angle_delta * i;
		cast_ray(engine->map, engine->player->pos, angle_actual);
		i++;
	}
	render_application();
	return (1);
}

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;
	void			*param[4];

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argv[1], &resolution);
	resize_application((int)resolution.x, (int)resolution.y);

	param[0] = malloc_color(255, 0, 0, 255);
	param[1] = malloc_color(0, 0, 255, 125);
	param[2] = malloc_vector2(75, 75);
	param[3] = malloc_vector2(75, 75);
	// draw_minimap(engine.map);
	// ft_printf("Player at %v / %d\n", engine.player->pos, (int)(engine.player->angle));
	add_interaction_to_application(KEYPRESS, handle_key, param);
	//render_funct_application(&draw_map, &engine);

	test_render_app(param);

	return (run_application());
}
