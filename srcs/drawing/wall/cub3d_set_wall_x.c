/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_wall_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:46:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:26:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_x(t_wall_calc *wall_calc, t_player *player)
{
	if (wall_calc->id == EAST || wall_calc->id == WEST)
		wall_calc->wall_x = player->pos.y
			+ wall_calc->wall_dist * wall_calc->ray_dir.y;
	else if (wall_calc->id == SOUTH || wall_calc->id == NORTH)
		wall_calc->wall_x = player->pos.x
			+ wall_calc->wall_dist * wall_calc->ray_dir.x;
	wall_calc->wall_x -= floor((wall_calc->wall_x));
}
