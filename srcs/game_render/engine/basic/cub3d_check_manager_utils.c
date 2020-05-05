/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_manager_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:52:36 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 16:59:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		run_ray(t_ray *info, t_player hero, t_vector2 *next_x,
															t_vector2 *next_y)
{
	if (info->pos.x == next_x->x && info->pos.y == next_x->y)
	{
		info->rounded.x += (info->ray.x > 0) ? 1 : -1;
		*next_x = create_vector2(hero.pos.x + (info->rounded.x * hero.size),
		hero.pos.y + ((info->rounded.x * tan(info->angle0)) * hero.size));
	}
	else if (info->pos.x == next_y->x && info->pos.y == next_y->y)
	{
		info->rounded.y += (info->ray.y > 0) ? 1 : -1;
		*next_y = create_vector2(hero.pos.x +
			((info->rounded.y / tan(info->angle0)) * hero.size),
			hero.pos.y + (info->rounded.y * hero.size));
	}
	info->pos = (vector2_distance(hero.pos, *next_x) <
				vector2_distance(hero.pos, *next_y)) ? *next_x : *next_y;
	info->fuck_float = (info->pos.x == next_x->x &&
									info->pos.y == next_x->y) ? 'x' : 'y';
}

t_vector2		calc_inter(t_vector2 point1, t_vector2 direction1,
										t_vector2 point2, t_vector2 direction2)
{
	float inter;

	inter = 0;
	if ((direction1.y == 1 || direction1.y == -1 || direction1.x == 0) &&
	(direction2.x == 1 || direction2.x == -1 || direction2.y == 0))
		return (create_vector2(point1.x, point2.y));
	inter = -((point1.y - (point1.x * (direction1.y / direction1.x))) -
	(point2.y - (point2.x * (direction2.y / direction2.x)))) /
	((direction1.y / direction1.x) - (direction2.y / direction2.x));
	return (create_vector2(inter, (direction1.y / direction1.x) * inter +
	(point1.y - (point1.x * (direction1.y / direction1.x)))));
}

void			type_initializer(int *x, int *y, t_ray info, t_player hero)
{
	*x = (info.fuck_float == 'x') ?
				ft_f_round(info.pos.x / hero.size) : info.pos.x / hero.size;
	*y = (info.fuck_float == 'y') ?
				ft_f_round(info.pos.y / hero.size) : info.pos.y / hero.size;
	if (info.ray.x < 0 && info.fuck_float == 'x')
		*x -= 1;
	else if (info.ray.y < 0 && info.fuck_float == 'y')
		*y -= 1;
	*x = (*x < 0) ? 0 : *x;
	*y = (*y < 0) ? 0 : *y;
}

void			check_ray(t_ray info, t_player hero,
											t_map map, t_sprites **lst_sprite)
{
	t_draw		act;
	float		pixel_b;
	float		pixel_h;
	float		result;
	int			nbr[2];
	
	act = create_draw(map, hero, &info, 0);
	result = vector2_distance(hero.pos, info.pos);
	result *= cos(info.angle * 0.95);
	result = ((map.resolution.y * 0.4f) * 10.0f) / result;
	pixel_h = (map.resolution.y / 2.0f) - (result / 2.0f);
	pixel_b = (map.resolution.y / 2.0f) + (result / 2.0f);
	nbr[0] = 0;
	while (nbr[0] < pixel_h)
		put_pixel(g_app->image,
			create_vector2(info.column, nbr[0]++), map.board[0][0]->ceiling);
	nbr[0] = pixel_b;
	while (nbr[0] < map.resolution.y)
		put_pixel(g_app->image,
			create_vector2(info.column, nbr[0]++), map.board[0][0]->floor);
	set_draw_point(&act, pixel_h, pixel_b, info.column);
	nbr[1] = type_condition(info, map, lst_sprite, hero);
	draw_column_block(act, nbr[1]);
	while ((*lst_sprite) != NULL)
		draw_many_sprite(map, lst_sprite, hero, info);
}

void			test_check(t_ray *info, t_player hero, t_map map,
														t_sprites **lst_sprite)
{
	t_vector2	next_x;
	t_vector2	next_y;

	info->angle0 = acos(info->ray.x / vector2_distance(create_vector2(0, 0),
		info->ray));
	info->angle0 = (info->ray.y > 0) ? info->angle0 : -info->angle0;
	info->rounded.x = (info->ray.x > 0) ?
		(((int)(hero.pos.x / hero.size)) + 1) - (hero.pos.x / hero.size) :
		((int)(hero.pos.x / hero.size)) - (hero.pos.x / hero.size);
	info->rounded.y = (info->ray.y > 0) ?
		(((int)(hero.pos.y / hero.size)) + 1) - (hero.pos.y / hero.size) :
		((int)(hero.pos.y / hero.size)) - (hero.pos.y / hero.size);
	next_x = create_vector2(hero.pos.x + (info->rounded.x * hero.size),
		hero.pos.y + ((info->rounded.x * tan(info->angle0)) * hero.size));
	next_y = create_vector2(hero.pos.x + ((info->rounded.y /
		tan(info->angle0)) * hero.size),
		hero.pos.y + (info->rounded.y * hero.size));
	info->pos = (vector2_distance(hero.pos, next_x) <
			vector2_distance(hero.pos, next_y)) ? next_x : next_y;
	info->fuck_float = (info->pos.x == next_x.x && info->pos.y == next_x.y) ?
			'x' : 'y';
	while (type_condition(*info, map, lst_sprite, hero) == 0)
	{
		run_ray(info, hero, &next_x, &next_y);
	}
}
