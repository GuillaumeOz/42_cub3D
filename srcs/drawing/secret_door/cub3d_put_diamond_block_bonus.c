/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_put_diamond_block_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:04:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:27:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	put_diamond_block_bonus(t_wall_calc *secret_door, t_engine *engine)
{
	while (secret_door->side_dist.x < 1.0f
		|| secret_door->side_dist.y < 1.0f)
	{
		if (secret_door->side_dist.x < secret_door->side_dist.y)
		{
			secret_door->side_dist.x += secret_door->delta_dist.x;
			secret_door->map_pos.x += secret_door->step.x;
		}
		else
		{
			secret_door->side_dist.y += secret_door->delta_dist.y;
			secret_door->map_pos.y += secret_door->step.y;
		}
		secret_door->map = list_at(engine->map, secret_door->map_pos.y);
		if (secret_door->map[secret_door->map_pos.x] == '0')
			return (true);
		else if (secret_door->map[secret_door->map_pos.x] == '1')
			return (false);
	}
	return (false);
}
