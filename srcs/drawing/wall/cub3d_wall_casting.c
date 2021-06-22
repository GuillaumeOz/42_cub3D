/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall_casting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:34:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 21:29:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_render(t_engine *engine, t_player *player)
{
	t_wall_calc	wall_calc;
	int			x;

	x = 0;
	wall_calc = create_wall_calc();
	while (x < engine->resolution.x)
	{
		set_camera_x(&wall_calc, engine, x);
		set_ray_dir(&wall_calc, player);
		set_map_pos(&wall_calc, player);
		set_delta_dist(&wall_calc);
		set_side_dist(&wall_calc, player);
		if (set_dda_calc(&wall_calc, engine) == true)
		{
			set_euclidean_wall_dist(&wall_calc, player);
			wall_drawing(&wall_calc, engine, player, x);
		}
		x++;
	}
}
