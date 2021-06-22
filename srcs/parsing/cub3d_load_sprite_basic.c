/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_load_sprite_basic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:36:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 18:18:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_sprite_basic(t_engine *engine, t_sprite_id id, int x, int y)
{
	t_sprite_list		*new_sprite_list;
	t_double_vector2	coord;

	coord = create_double_vector2(x + 0.5f, y + 0.5f);
	if (engine->sprite_basic == NULL)
		cub3d_error(ERROR_PARSING32,
			"Basic Sprite informations cannot be load");
	engine->sprites_num += 1;
	new_sprite_list = malloc_sprite_list(id, coord);
	list_push_back(engine->sprite_list, new_sprite_list);
}
