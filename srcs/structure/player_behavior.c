/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behavior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 19:51:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/16 20:26:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_actor		create_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir, float p_speed)
{
	t_actor result;
	float	rad;
	int		corrector;

	corrector = 180;
	result.pos = p_pos;
	result.team = p_team;
	result.angle = ((90 * (int)(p_dir)) - corrector);
	rad = degree_to_radian(result.angle);
	result.forward = create_vector2(cos(rad), sin(rad));
	rad = degree_to_radian(result.angle + 90);
	result.right = create_vector2(cos(rad), sin(rad));
	result.speed = p_speed;
	result.size = 10;
	result.pitch = 0;
	result.fov = 70;
	result.control = 0;
	result.hp = 100;
	return (result);
}

t_player	reset_player(int p_hp)
{
	t_player result;

	result.pos = create_vector2(0, 0);
	result.speed = 0.2;
	result.movement = create_vector2(0, 0);
	result.last_movement = create_vector2(0, 0);
	result.pitch = 0;
	result.radius = 0.2;
	result.size = 10;
	result.fov = 80;
	result.hp = p_hp;
	result.to_front = false;
	result.to_left = false;
	result.to_back = false;
	result.to_right = false;
	result.interact = false;
	result.interact = false;
	result.turn_right = false;
	result.turn_left = false;
	result.fire = false;
	return (result);
}
