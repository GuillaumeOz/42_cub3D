/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:33:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/17 12:43:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#define FOV 70.0f

t_application *g_app;

typedef int (*t_key_funct)(int key, void *param);
typedef int (*t_render_funct)(void *param);

int handle_key(int key, void *param)
{
	static int move_speed = 3;
	t_vector2 *pos;
	t_vector2 *pos2;

	pos = ((void **)(param))[2];
	pos2 = ((void **)(param))[3];

	if (key == ESC_KEY)
		exit(0);
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

void add_key_to_application(int event, t_key_funct funct, void *param)
{
	mlx_hook(g_app->win_ptr, event, 0, funct, param);
}

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

void render_funct_application(void *param)
{
	mlx_loop_hook(g_app->mlx_ptr, test_render_app, param);
}

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;
	int				fd;

	start_application(600, 600, "Cub3D (c)");

	engine = create_game_engine();//fill up this part


	t_config		*config;
	void			*param[4];

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Coucou");
	fd = open(argv[1])

	application_create_content();
	config = cube_formatter("Cube3D", argv[1]);
	param[0] = malloc_color(255, 0, 0, 255);
	param[1] = malloc_color(0, 0, 255, 125);
	param[2] = malloc_vector2(75, 75);
	param[3] = malloc_vector2(75, 75);

	// test_render_app(param);
	add_key_to_application(KEYPRESS, &handle_key, param);
	render_funct_application(param);
	//Boucle et attends les events.

	return (run_application());
}
