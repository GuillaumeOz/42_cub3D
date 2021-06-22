/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_tex_coord_from_wall_x.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:52:26 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 17:58:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_x_from_wall_x(t_wall_calc *wall_calc, t_engine *engine)
{
	t_texture	*texture;

	if (wall_calc->hit_char == '1')
	{
		texture = engine->texture[wall_calc->id];
		wall_calc->tex.x = (int)(wall_calc->wall_x
				* (double)(texture->tex_resolution.x));
		wall_calc->tex.x = texture->tex_resolution.x
			- wall_calc->tex.x - 1;
	}
	else
	{
		texture = engine->secret_door;
		wall_calc->tex.x = (int)(wall_calc->wall_x
				* ((double)(texture->tex_resolution.x) / 11));
		wall_calc->tex.x = texture->tex_resolution.x / 11
			- wall_calc->tex.x - 1;
	}
}
