/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_tex_y_limit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:39:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:19:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_y_limit(t_wall_calc *wall_calc, t_engine *engine)
{
	t_texture	*texture;

	if (wall_calc->hit_char == '1')
	{
		texture = engine->texture[wall_calc->id];
		wall_calc->tex.y = (int)wall_calc->tex_pos
			& (texture->tex_resolution.y - 1);
	}
	else
	{
		texture = engine->secret_door;
		wall_calc->tex.y = (int)wall_calc->tex_pos
			& (texture->tex_resolution.y - 1);
	}
}
