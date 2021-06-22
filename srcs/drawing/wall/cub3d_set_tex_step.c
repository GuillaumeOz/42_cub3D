/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_tex_step.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:36:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:20:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_step(t_wall_calc *wall_calc, t_engine *engine)
{
	t_texture	*texture;

	if (wall_calc->hit_char == '1')
	{
		texture = engine->texture[wall_calc->id];
		wall_calc->tex_step = 1.0 * texture->tex_resolution.y
			/ wall_calc->line_height;
	}
	else
	{
		texture = engine->secret_door;
		wall_calc->tex_step = 1.0 * texture->tex_resolution.y
			/ wall_calc->line_height;
	}
}
