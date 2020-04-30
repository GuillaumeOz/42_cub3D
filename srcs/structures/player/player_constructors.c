/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:10:26 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/30 20:07:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_player	create_player(t_vector2 p_pos, float p_dir, float p_speed)
{
	t_player	result;

	result.pos = create_vector2(p_pos.x, p_pos.y);
	result.move_speed = 0.2;
	result.rotation_speed = 0.15;
	result.bonus_speed = p_speed;
	result.movement = create_vector2(0, 0);
	result.last_movement = create_vector2(0, 0);
	result.pitch = p_dir;
	result.radius = 0.2;
	result.size = 10;
	result.fov = 80;
	result.hp = 100;
	result.control = NOEVENTMASK;
	return (result);
}

t_player	*malloc_player(t_vector2 p_pos, float p_dir, float p_step)
{
	t_player *result;

	result = (t_player*)malloc(sizeof(t_player));
	if (result == NULL)
		catch_error(MALLOC_PLAYER_1);
	*result = create_player(p_pos, p_dir, p_step);
	return (result);
}

void		set_player_status(t_player *hero, t_map *map)
{
	(void)map;
	hero->size = 10;
	hero->radius *= hero->size;
	hero->pos.x = (hero->pos.x * hero->size) - (hero->size / 2) + 10;
	hero->pos.y = (hero->pos.y * hero->size) + (hero->size / 2);
}
