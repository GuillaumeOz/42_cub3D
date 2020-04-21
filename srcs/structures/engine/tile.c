/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:34:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 20:02:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_tile create_tile(t_tile_type p_type, t_color p_ceiling, t_color p_floor)
{
	t_tile result;

	result.type = p_type;
	result.ceiling = p_ceiling;// change this later
	result.floor = p_floor;
	result.texture = (t_texture**)malloc(sizeof(t_texture *) * 4);
	if (result.texture == NULL)
		catch_error(CREATE_TILE_1);
	return (result);
}

t_tile *malloc_tile(t_tile_type p_type, t_color p_ceiling, t_color p_floor)
{
	t_tile *result;

	result = (t_tile *)malloc(sizeof(t_tile));
	if (result == NULL)
		catch_error(CREATE_TILE_2);
	*result = create_tile(p_type, p_ceiling, p_floor);
	return (result);
}

void 	destroy_tile(t_tile to_destroy)
{
	(void)to_destroy;
}

void 	free_tile(t_tile *to_free)
{
	destroy_tile(*to_free);
	free(to_free);
}

void set_tile_texture(t_tile *tile, t_direction dir, t_texture *p_texture)
{
	tile->texture[(int)(dir)] = p_texture;
}
