/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_ray_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:25:43 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:18:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_dir(t_wall_calc *wall_calc, t_player *player)
{
	wall_calc->ray_dir = create_double_vector2(player->dir.x
			- player->plane.x * wall_calc->camera_x, player->dir.y
			- player->plane.y * wall_calc->camera_x);
}
