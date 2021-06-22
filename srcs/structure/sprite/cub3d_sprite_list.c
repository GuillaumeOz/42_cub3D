/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:28:54 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:45:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite_list	*malloc_sprite_list(t_sprite_id id, t_double_vector2 coord)
{
	t_sprite_list	*sprite_list;

	sprite_list = NULL;
	sprite_list = (t_sprite_list *)malloc(sizeof(t_sprite_list));
	if (sprite_list == NULL)
		cub3d_error(ERROR_SPRITE_LIST1, "t_sprite_list* cannot be malloc");
	*sprite_list = create_sprite_list(id, coord);
	return (sprite_list);
}

t_sprite_list	create_sprite_list(t_sprite_id id, t_double_vector2 coord)
{
	t_sprite_list	sprite_list;

	sprite_list.id = id;
	sprite_list.coord = create_float_vector2(coord.x, coord.y);
	sprite_list.dist = 0.0f;
	sprite_list.sprite_width_axis = 1.0f;
	sprite_list.sprite_height_axis = 1.0f;
	sprite_list.sprite_z_axis = 0.0f;
	sprite_list.sprite_width = 0;
	sprite_list.sprite_height = 0;
	sprite_list.sprite_z = 0;
	sprite_list.fog_war = 255.0f;
	sprite_list.animation = 0;
	sprite_list.enable = true;
	return (sprite_list);
}

void	free_sprite_list(t_list *to_free)
{
	free_list(to_free, &free);
}
