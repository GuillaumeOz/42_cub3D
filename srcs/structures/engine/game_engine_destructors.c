/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_destructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:26:00 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/08 16:39:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		destroy_engine_tile(t_game_engine *to_destroy)
{
	free_tile(to_destroy->empty_tile);
	free_tile(to_destroy->wall_tile);
	free_tile(to_destroy->sprite_tile);
	free_tile(to_destroy->door_tile);
	free_tile(to_destroy->closed_door_tile);
	free_tile(to_destroy->secret_tile);
	free_tile(to_destroy->dead_tile);
	free_tile(to_destroy->medikit_tile);
	free_tile(to_destroy->monster_tile);
}

void			destroy_game_engine(t_game_engine to_destroy)
{
	destroy_vector2(to_destroy.resolution);
	free_texture(to_destroy.texture[0]);
	free_texture(to_destroy.texture[1]);
	free_texture(to_destroy.texture[2]);
	free_texture(to_destroy.texture[3]);
	free(to_destroy.texture);
	free_texture(to_destroy.sprite);
	destroy_texture(to_destroy.door);
	destroy_texture(to_destroy.secret);
	free_color(to_destroy.ceiling);
	free_color(to_destroy.floor);
	destroy_engine_tile(&to_destroy);
	free_list(to_destroy.map_content, free);
	free_map(to_destroy.map);
	free_player(to_destroy.player);
	destroy_monster(to_destroy.monster);
	destroy_medikit(to_destroy.medikit);
	free(to_destroy.comp);
	free(to_destroy.valid);
}

void			free_game_engine(t_game_engine *to_free)
{
	destroy_game_engine(*to_free);
	free(to_free);
}
