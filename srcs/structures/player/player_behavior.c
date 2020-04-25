/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behavior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 19:51:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/25 22:06:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	bool	hit_player_wall(t_tile_type type)//change this with the type
{
	// empty = 0,
	// wall = 1, ?
	// sprite = 2,
	// door = 3, ?
	// closed_door = 4, ?
	// level = 5, ?
	// medikit = 6,
	// monster = 7,
	// dead_monster = 8,
	// ("0DMmH2")
	if ( type == empty || type == door || type == monster ||
	type == dead_monster ||  type == medikit || type == sprite )
		return (true);
	return (false);
}

void	player_hitbox(t_player *h, t_vector2 mvt, t_map map, int sign)//check sign value
{
	float	post_pos;
	float	last_pos;

	post_pos = h->pos.x + (mvt.x * h->speed * sign);//add mov speed bonus L_SHFT
	last_pos = h->pos.x;
	if ((hit_player_wall(map.board[(int)((h->pos.y + h->radius) /
		(h->size))][(int)((post_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((h->pos.y - h->radius) /
		(h->size))][(int)((post_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((h->pos.y + h->radius) /
		(h->size))][(int)((post_pos - h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((h->pos.y - h->radius) /
		(h->size))][(int)((post_pos - h->radius) / (h->size))]->type)))
		h->pos.x += mvt.x * h->speed * sign;
	post_pos = h->pos.y + (mvt.y * h->speed * sign);
	if ((hit_player_wall(map.board[(int)((post_pos + h->radius) /
		(h->size))][(int)((last_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((post_pos - h->radius) /
		(h->size))][(int)((last_pos + h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((post_pos + h->radius) /
		(h->size))][(int)((last_pos - h->radius) / (h->size))]->type)) &&
		(hit_player_wall(map.board[(int)((post_pos - h->radius) /
		(h->size))][(int)((last_pos - h->radius) / (h->size))]->type)))
		h->pos.y += mvt.y * h->speed * sign;
}

t_player	reset_player(int p_hp)
{
	t_player result;
	float	rad;
	int		corrector;

	corrector = 180;
	result.pos = create_vector2(0, 0);
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
