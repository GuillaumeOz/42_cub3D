/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw_constructor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:06:18 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/28 17:37:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_draw	create_draw(t_map p_map, t_player p_hero, void *p_info, int type)
{
	t_draw	result;
	t_ray	info;
	float	math;

	if (type == 1)
		info = ((t_sprites*)(p_info))->ray;
	else
		info = *(t_ray*)p_info;
	result.info = p_info;
	result.map = p_map;
	result.hero = p_hero;
	math = vector2_distance(p_hero.pos, info.pos);
	math *= cos(info.angle * 0.95);
	result.alpha = (255 * 3.0f * p_hero.size) / math;
	result.alpha = (result.alpha > 255) ? 255 : result.alpha;
	result.start = create_vector2(0, 0);
	result.end = create_vector2(0, 0);
	return (result);
}
