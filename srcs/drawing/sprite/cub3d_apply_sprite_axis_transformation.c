/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_apply_sprite_axis_transformation.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:29:55 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:42:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	apply_sprite_height_transformation(t_engine *engine,
	t_player *player, int i)
{
	if (player->control & O_CTRL)
		set_sprite_list_height_axis(engine->sprite_list, i, 0.5f);
	if (player->control & L_CTRL)
		set_sprite_list_height_axis(engine->sprite_list, i, (-0.5f));
}

void	apply_sprite_width_transformation(t_engine *engine,
	t_player *player, int i)
{
	if (player->control & I_CTRL)
		set_sprite_list_width_axis(engine->sprite_list, i, 0.5f);
	if (player->control & K_CTRL)
		set_sprite_list_width_axis(engine->sprite_list, i, (-0.5f));
}

void	apply_sprite_z_transformation(t_engine *engine,
	t_player *player, int i)
{
	if (player->control & U_CTRL)
		set_sprite_list_z_axis(engine->sprite_list, i, 10.0f);
	if (player->control & J_CTRL)
		set_sprite_list_z_axis(engine->sprite_list, i, (-10.0f));
}

void	apply_sprite_axis_transformation(t_engine *engine,
	t_player *player, int i)
{
	if (player->control & TRANSFORM_MARKER && engine->sprites_num == 1)
	{
		if (player->control & U_CTRL || player->control & J_CTRL)
			apply_sprite_z_transformation(engine, player, i);
		if (player->control & I_CTRL || player->control & K_CTRL)
			apply_sprite_width_transformation(engine, player, i);
		if (player->control & O_CTRL || player->control & L_CTRL)
			apply_sprite_height_transformation(engine, player, i);
	}
}
