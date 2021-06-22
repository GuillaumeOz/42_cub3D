/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_euclidean_wall_dist.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:12:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:25:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_euclidean_wall_dist(t_wall_calc *wall_calc, t_player *player)
{
	if (wall_calc->id == EAST || wall_calc->id == WEST)
		wall_calc->wall_dist = (wall_calc->map_pos.x - player->pos.x
				+ (1 - wall_calc->step.x) / 2) / wall_calc->ray_dir.x;
	else if (wall_calc->id == SOUTH || wall_calc->id == NORTH)
		wall_calc->wall_dist = (wall_calc->map_pos.y - player->pos.y
				+ (1 - wall_calc->step.y) / 2) / wall_calc->ray_dir.y;
}
