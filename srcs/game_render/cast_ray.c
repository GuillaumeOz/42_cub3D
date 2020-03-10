/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:57:02 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/10 17:26:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

void 		*calc_detection(t_map *map, t_vector2 pos)
{
	int x;
	int y;
	// x = pos.x > (int)(pos.x) + 0.5f ? (int)(pos.x) + 1 : (int)(pos.x) + 1;
	// y = pos.y > (int)(pos.y) + 0.5f ? (int)(pos.y) + 1 : (int)(pos.y) + 1;
	x = (int)pos.x + 1;
	y = (int)pos.y + 1;

	// printf("FLOAT VALUE\n");
	// printf("(%f,%f)\n", pos.x, pos.y);
	// printf("INT VALUE\n");
	// printf("(%d,%d)\n", x, y);
	if (map->board[x][y]->type == wall)
		return (map->board[x][y]);
	return (NULL);
}

float		calc_dist(t_vector2 p1, t_vector2 p2)
{
	float result;

	result = pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
	return (result);
}

t_vector2	cast_ray(t_map *map, t_vector2 actual, float angle)
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
