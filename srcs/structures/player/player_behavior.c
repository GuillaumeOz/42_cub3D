/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behavior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 19:51:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/08 17:08:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	hit_player_wall(t_tile_type type)
{
	if (type == empty || type == monster || type == dead_monster ||
		type == medikit || type == closed_door)
		return (true);
	return (false);
}

void			player_hitbox(t_player *h, t_vector2 mvt, t_map map, int sign)
{
	float	post_pos;
	float	last_pos;

	post_pos = h->pos.x + h->bonus_speed * (mvt.x * h->move_speed * sign);
	last_pos = h->pos.x;
	if ((hit_player_wall(map.board[(int)((h->pos.y + h->radius) /
		(h->size))][(int)((post_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((h->pos.y - h->radius) /
		(h->size))][(int)((post_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((h->pos.y + h->radius) /
		(h->size))][(int)((post_pos - h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((h->pos.y - h->radius) /
		(h->size))][(int)((post_pos - h->radius) / (h->size))]->type)))
		h->pos.x += (h->bonus_speed * (mvt.x * h->move_speed * sign));
	post_pos = (h->pos.y + h->bonus_speed * (mvt.y * h->move_speed * sign));
	if ((hit_player_wall(map.board[(int)((post_pos + h->radius) /
		(h->size))][(int)((last_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((post_pos - h->radius) /
		(h->size))][(int)((last_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((post_pos + h->radius) /
		(h->size))][(int)((last_pos - h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((post_pos - h->radius) /
		(h->size))][(int)((last_pos - h->radius) / (h->size))]->type)))
		h->pos.y += (h->bonus_speed * (mvt.y * h->move_speed * sign));
}

t_player		reset_player(int p_hp)
{
	t_player result;

	result.bonus_speed = PLAYER_SPEED;
	result.pos = create_vector2(0, 0);
	result.move_speed = 0.2;
	result.rotation_speed = 0.15;
	result.movement = create_vector2(0, 0);
	result.last_movement = create_vector2(0, 0);
	result.pitch = 0;
	result.radius = 0.2;
	result.size = 10;
	result.fov = 80;
	result.hp = p_hp;
	result.control = NOEVENTMASK;
	return (result);
}
