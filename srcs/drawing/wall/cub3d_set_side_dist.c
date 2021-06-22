/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_side_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:00:01 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:21:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_side_dist(t_wall_calc *wall_calc, t_player *player)
{
	if (wall_calc->ray_dir.x < 0)
	{
		wall_calc->step.x = -1;
		wall_calc->side_dist.x = (player->pos.x - wall_calc->map_pos.x)
			* wall_calc->delta_dist.x;
	}
	else
	{
		wall_calc->step.x = 1;
		wall_calc->side_dist.x = (wall_calc->map_pos.x + 1.0 - player->pos.x)
			* wall_calc->delta_dist.x;
	}
	if (wall_calc->ray_dir.y < 0)
	{
		wall_calc->step.y = -1;
		wall_calc->side_dist.y = (player->pos.y - wall_calc->map_pos.y)
			* wall_calc->delta_dist.y;
	}
	else
	{
		wall_calc->step.y = 1;
		wall_calc->side_dist.y = (wall_calc->map_pos.y + 1.0 - player->pos.y)
			* wall_calc->delta_dist.y;
	}
}
