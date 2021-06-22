/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_sprite_pos_compared_to_player.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:37:54 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:34:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite_pos_compared_to_player(t_sprite_calc *sprite_calc,
	t_engine *engine, t_player *player, int i)
{
	t_float_vector2	sprite_coord;

	sprite_coord = get_sprite_list_coord(engine->sprite_list,
			sprite_calc->sprite_order[i]);
	sprite_calc->sprite_pos = create_float_vector2(sprite_coord.x
			- player->pos.x, sprite_coord.y - player->pos.y);
}
