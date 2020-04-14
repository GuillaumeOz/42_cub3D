/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:38:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 20:34:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define ANGLE_BEGIN (engine->player->angle + FOV / 2)
#define ANGLE_DELTA (FOV / g_app->size.x)
#define FISH_EYE (cos(degree_to_radian(ANGLE_DELTA * i - FOV / 2)))

// typedef struct	s_image
// {
// 	t_vector2	size;
// 	void		*img_ptr;
// 	char		*pixels;
// 	int			bits_per_pixels;
// 	int			size_line;
// 	int			endian;
// }				t_image;

// void	draw_texture(t_game_engine *engine)
// {
// 	// while (i < (engine->map->size.x * engine->map->size.y))
// 	// {
// 	// 	put_pixel(g_app->image);(g_app->size.x - i) (g_app->size.y - height) / 2)
// 	// 	draw_rectangle_in_image(g_app->image, pos, size, color);
// 	// 	i + engine->map->size.y;
// }

// void	draw_wall(t_game_engine *engine, t_vector2 impact, int i)
// {
// 	t_vector2	rect_pos;
// //	t_vector2	rect_hei;
// //	t_color		rect_color;
// 	float		dist;
// 	float		height;

// 	dist = sqrt(calc_dist(engine->player->pos, impact));
// 	//h = 40 | d = 3
// 	height = ((0.40 * g_app->size.y) * 3) / (dist * FISH_EYE);
// 	rect_pos = create_vector2((g_app->size.x - i), (g_app->size.y - height) / 2);
// //	rect_hei = create_vector2(1, height);
// //	rect_color = create_color(120, 120, 120, 255);
// //	draw_rectangle(rect_pos, rect_hei, rect_color);
// 	draw_texture(engine, rect_pos, i);
// }

void	draw_env(t_game_engine *engine)
{
	t_vector2	top_pos;
	t_vector2	mid_pos;
	t_vector2	rect_size;
	t_color		clear;

	top_pos = create_vector2(0, 0);
	mid_pos = create_vector2(0, g_app->size.y / 2);
	rect_size = create_vector2(g_app->size.x, g_app->size.y / 2);
	clear = create_color(50, 50, 50, 255);
	clear_application(clear);
	draw_rectangle(top_pos, rect_size, *(engine->ceiling));
	draw_rectangle(mid_pos, rect_size, *(engine->floor));
	//add floor and ceilling texture later
}

int		draw_map(void *param)
{
	t_game_engine *engine;
	t_vector2     impact;
	float         angle_actual;
	size_t        i;

    engine = (t_game_engine *)(param);	
	draw_env(engine);
	i = 0;
	//PRINTV(engine->player->forward.x, engine->player->forward.y)
	while (i <= g_app->size.x)
	{
		angle_actual = ANGLE_BEGIN - ANGLE_DELTA * i;
		impact = cast_ray(engine->map, engine->player->pos, angle_actual);
		draw_wall(engine, impact, i);
		draw_wall(*(engine->player), engine->map);
		i++;
	}
	render_application();
	return (0);
}
