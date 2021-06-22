/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_calculation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:48:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:00:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_sprite	*sprite_selector(t_engine *engine, t_sprite_list *sprite)
{
	if (sprite->id == BASIC)
		return (engine->sprite_basic);
	return (engine->sprite_basic);
}

void	sprite_calculation(t_sprite_calc *sprite_calc,
	t_engine *engine, t_player *player, int i)
{
	t_sprite_list	*current_sprite;
	t_sprite		*sprite_tex;

	current_sprite = list_at(engine->sprite_list, i);
	if (get_sprite_list_dist(engine->sprite_list, i) < 1.0f)
		apply_sprite_axis_transformation(engine, player, i);
	set_sprite_pos_compared_to_player(sprite_calc, engine, player, i);
	set_inv_camera_matrice_transformation(sprite_calc, player);
	set_sprite_screen_x(sprite_calc, engine);
	set_sprite_axis_transformation(sprite_calc, engine, current_sprite);
	sprite_tex = sprite_selector(engine,
			sprite_calc->sprite_list[sprite_calc->sprite_order[i]]);
	sprite_drawing(sprite_calc, engine, current_sprite, sprite_tex);
}
