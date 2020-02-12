/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:54:50 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/12 21:21:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_application *g_app;
typedef int (*t_key_funct)(int key, void *param);
typedef int (*t_render_funct)(void *param);

// void	draw_circle_debug(t_vector2 pos, int radius, t_color color)
// {
// 	draw_circle_in_image_debug(g_app->image, pos, radius, color);
// }

// void	draw_circle_in_image_debug(t_image *image, t_vector2 pos, int radius, t_color color)
// {
// 	t_vector2	actual_pos;
// 	size_t		i;
// 	size_t		j;

// 	i = 0;
// 	pos = create_vector2((actual_pos.x - radius), (actual_pos.y - radius));
// 	while (i < (pos.x + radius))
// 	{
// 		j = 0;
// 		actual_pos.y = i;
// 		while (j < (pos.y + radius))
// 		{
// 			if (pow(radius, 2) >= (pow(actual_pos.x - pos.x, 2) + pow(actual_pos.y - pos.y, 2)))
// 			{
// 				put_pixel(image, actual_pos.x, actual_pos.y, color);
// 			}
// 			j++;
// 			actual_pos.x = j;
// 		}
// 	}
// }

static int handle_key(int key, void *param)
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

static int test_render_app(void *param) // -> void **param
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

static void render_funct_application(t_render_funct funct, void *param)
{
	mlx_loop_hook(g_app->mlx_ptr, test_render_app, param);
}

int main(int argc, char **argv)
{
	t_config		*config;
	void			*param[4];

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Coucou");
	application_create_content();
	param[0] = malloc_color(255, 0, 0, 255);
	param[1] = malloc_color(0, 0, 255, 125);
	param[2] = malloc_vector2(75, 75);
	param[3] = malloc_vector2(75, 75);
	
	config = cube_formatter("Cube3D", argv[1]);
	g_app->image = malloc_image(600, 600);
	// draw_rectangle(create_vector2(200.0f, 200.0f), create_vector2(200.0f, 200.0f), create_color(0, 0, 0, 255));
	// draw_circle_debug(create_vector2(300.0f, 300.0f), 100, create_color(255, 255, 255, 255));
	add_key_to_application(KEYPRESS, &handle_key, param);
	render_funct_application(&test_render_app, param);
	// render_funct_application();

	return (run_application());
}

// t_application *g_app;

// typedef int (*t_key_funct)(int key, void *param);
// typedef int (*t_render_funct)(void *param);

// int handle_key(int key, void *param)
// {
// 	static int move_speed = 3;
// 	t_vector2 *pos;
// 	t_vector2 *pos2;

// 	pos = ((void **)(param))[2];
// 	pos2 = ((void **)(param))[3];

// 	if (key == ESC_KEY)
// 		close_application();
// 	if (key == NK4_KEY && move_speed > 1)
// 		move_speed--;
// 	if (key == NK6_KEY && move_speed < 10)
// 		move_speed++;
// 	if (key == A_KEY)
// 		pos->x -= move_speed;
// 	if (key == D_KEY)
// 		pos->x += move_speed;
// 	if (key == W_KEY)
// 		pos->y -= move_speed;
// 	if (key == S_KEY)
// 		pos->y += move_speed;
// 	if (key == LEFT_KEY)
// 		pos2->x -= move_speed;
// 	if (key == RIGHT_KEY)
// 		pos2->x += move_speed;
// 	if (key == UP_KEY)
// 		pos2->y -= move_speed;
// 	if (key == DOWN_KEY)
// 		pos2->y += move_speed;
// 	return (0);
// }

// void add_key_to_application(int event, t_key_funct funct, void *param)
// {
// 	mlx_hook(g_app->win_ptr, event, 0, funct, param);
// }

// int test_render_app(void *param) // -> void **param
// {
// 	t_color *color;
// 	t_color *color2;
// 	t_vector2 *pos;
// 	t_vector2 *pos2;

// 	color = ((void **)(param))[0];
// 	color2 = ((void **)(param))[1];
// 	pos = ((void **)(param))[2];
// 	pos2 = ((void **)(param))[3];

// 	clear_application(create_color(50, 50, 50, 255));

// 	draw_rectangle(*pos, create_vector2(150, 50), *color);
// 	draw_rectangle(*pos2, create_vector2(150, 50), *color2);

// 	render_application();

// 	return (0);
// }

// void render_funct_application(void *param)
// {
// 	mlx_loop_hook(g_app->mlx_ptr, test_render_app, param);
// }

// int main()
// {

// 	//Malloc une application.
// 	start_application(840, 680, "Title");
// 	application_create_content();
// 	//Clear et rempli d'une couleur donnee.

// 	void *param[4];
// 	param[0] = malloc_color(255, 0, 0, 255);
// 	param[1] = malloc_color(0, 0, 255, 125);
// 	param[2] = malloc_vector2(75, 75);
// 	param[3] = malloc_vector2(75, 75);

// 	// test_render_app(param);
// 	add_key_to_application(KEYPRESS, &handle_key, param);
// 	render_funct_application(param);
// 	//Boucle et attends les events.

// 	return (run_application());
// }
