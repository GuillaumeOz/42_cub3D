/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:34:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 18:26:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tile create_tile(t_game_engine p_engine, t_tile_type p_type)
{
	t_tile result;

	result.type = p_type;
	result.ceiling = *(p_engine.ceiling);
	result.floor = *(p_engine.floor);
	result.sprite = *(p_engine.sprite);
	result.door = p_engine.door;
	result.secret = p_engine.secret;
	result.medikit = p_engine.medikit;
	result.monster = p_engine.monster;
	result.texture = (t_texture**)malloc(sizeof(t_texture*) * 4);// free this
	if (result.texture == NULL)
		catch_error(CREATE_TILE_1);
	return (result);
}

t_tile *malloc_tile(t_game_engine p_engine, t_tile_type p_type)
{
	t_tile *result;

	result = (t_tile *)malloc(sizeof(t_tile));
	if (result == NULL)
		catch_error(CREATE_TILE_2);
	*result = create_tile(p_engine, p_type);
	set_tile_texture(result, north, p_engine.texture[north]);//check the desctructor
	set_tile_texture(result, east, p_engine.texture[east]);
	set_tile_texture(result, south, p_engine.texture[south]);
	set_tile_texture(result, west, p_engine.texture[west]);
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

void	set_tile_texture(t_tile *tile, t_direction dir, t_texture *p_texture)
{
	tile->texture[(int)(dir)] = p_texture;
}
