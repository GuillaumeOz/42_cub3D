/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actorr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:42:38 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 17:02:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_player	create_player(t_vector2 p_pos, t_direction p_dir, float p_speed)
{
	t_player result;
	float	rad;
	int		corrector;

	corrector = 180;
	result.pos = p_pos;
	result.angle = ((90 * (int)(p_dir)) - corrector);
	result.movement = create_vector2(0, 0);
	result.last_movement = create_vector2(0, 0);
	rad = degree_to_radian(result.angle);
	result.forward = create_vector2(cos(rad), sin(rad));
	rad = degree_to_radian(result.angle + 90);
	result.right = create_vector2(cos(rad), sin(rad));
	result.speed = p_speed;
	result.size = 10;
	result.pitch = 0;
	result.radius = 0.2;
	result.fov = 70;
	result.control = 0;
	result.hp = 100;
	return (result);
}

t_player	*malloc_player(t_vector2 p_pos, t_direction p_dir, float p_step)
{
	t_player *result;

	result = (t_player *)malloc(sizeof(t_player));
	if (result == NULL)
		return (NULL);
	*result = create_player(p_pos, p_dir, p_step);
	return (result);
}

void		destroy_player(t_player to_destroy)
{
	(void)to_destroy;
}

void		free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}
