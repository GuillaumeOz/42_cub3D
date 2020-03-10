/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:42:38 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/10 09:32:59 by gozsertt         ###   ########.fr       */
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
	return (result);
}

t_actor		*malloc_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir, float p_step)
{
	t_actor *result;

	result = (t_actor *)malloc(sizeof(t_actor));
	if (result == NULL)
		return (NULL);
	*result = create_actor(p_pos, p_team, p_dir, p_step);
	return (result);
}

void		destroy_actor(t_actor to_destroy)
{
	(void)to_destroy;
}

void		free_actor(t_actor *to_free)
{
	destroy_actor(*to_free);
	free(to_free);
}
