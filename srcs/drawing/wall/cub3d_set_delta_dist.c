/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_delta_dist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:51:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:28:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_delta_dist(t_wall_calc *wall_calc)
{
	wall_calc->delta_dist = create_double_vector2(sqrt(1
				+ (wall_calc->ray_dir.y * wall_calc->ray_dir.y)
				/ (wall_calc->ray_dir.x * wall_calc->ray_dir.x)),
			sqrt(1 + (wall_calc->ray_dir.x * wall_calc->ray_dir.x)
				/ (wall_calc->ray_dir.y * wall_calc->ray_dir.y)));
}
