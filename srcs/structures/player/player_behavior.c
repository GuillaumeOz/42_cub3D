/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behavior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 19:51:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 16:44:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	bool	hit_player_wall(t_map *map, t_vector2 pos)
{
	int x;
	int y;

	x = (int)(pos.x);
	y = (int)(pos.y);
	if (map->board[x][y]->type == wall)
		return (true);
	return (false);
}

void			player_hitbox(t_map *map, t_vector2 *pos, t_vector2 mov, float speed)
{
	float dot;
	float y;
	float x;

	dot = 0.1f;
	x = mov.x * speed;
	while (hit_player_wall(map, create_vector2(pos->x + x - dot, pos->y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + x + dot, pos->y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + x - dot, pos->y - dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + x + dot, pos->y - dot)) == true)
			x += x < 0 ? 0.1f: -0.1f;
	y = mov.y * speed;
	while (hit_player_wall(map, create_vector2(pos->x - dot, pos->y + y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + dot, pos->y + y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x - dot, pos->y + y - dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + dot, pos->y + y - dot)) == true)
			y += y < 0 ? 0.1f: -0.1f;
	*pos = add_vector2_to_vector2(*pos, create_vector2(x, y));
}

t_player	reset_player(int p_hp)
{
	t_player result;
	float	rad;
	int		corrector;

	corrector = 180;
	result.pos = create_vector2(0, 0);
	result.team = ally;
	result.angle = ((90 * (int)(north)) - corrector);
	rad = degree_to_radian(result.angle);
	result.forward = create_vector2(cos(rad), sin(rad));
	rad = degree_to_radian(result.angle + 90);
	result.right = create_vector2(cos(rad), sin(rad));
	result.speed = player_speed;
	result.size = 10;
	result.pitch = 0;
	result.fov = 70;
	result.control = NOEVENTMASK;
	result.hp = p_hp;
	return (result);
}
