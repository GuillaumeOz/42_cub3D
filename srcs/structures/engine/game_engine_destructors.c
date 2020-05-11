/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_destructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:26:00 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/10 14:58:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		destroy_engine_bonus(t_game_engine *to_destroy)
{
	if (to_destroy->door.path != NULL)
		destroy_texture(to_destroy->door);
	if (to_destroy->secret.path != NULL)
		destroy_texture(to_destroy->secret);
	if (to_destroy->monster.life.path != NULL ||
	to_destroy->monster.dead.path != NULL)
		destroy_monster(to_destroy->monster);
	if (to_destroy->medikit.tex.path != NULL)
		destroy_medikit(to_destroy->medikit);
}

static void		destroy_engine_tile(t_game_engine *to_destroy)
{
	if (to_destroy->empty_tile != NULL)
		free_tile(to_destroy->empty_tile);
	if (to_destroy->wall_tile != NULL)
		free_tile(to_destroy->wall_tile);
	if (to_destroy->sprite_tile != NULL)
		free_tile(to_destroy->sprite_tile);
	if (to_destroy->door_tile != NULL)
		free_tile(to_destroy->door_tile);
	if (to_destroy->closed_door_tile != NULL)
		free_tile(to_destroy->closed_door_tile);
	if (to_destroy->secret_tile != NULL)
		free_tile(to_destroy->secret_tile);
	if (to_destroy->dead_tile != NULL)
		free_tile(to_destroy->dead_tile);
	if (to_destroy->medikit_tile != NULL)
		free_tile(to_destroy->medikit_tile);
	if (to_destroy->monster_tile != NULL)
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
	free_color(to_destroy.ceiling);
	free_color(to_destroy.floor);
	destroy_engine_tile(&to_destroy);
	free_list(to_destroy.map_content, free);
	free_map(to_destroy.map);
	free_player(to_destroy.player);
	destroy_engine_bonus(&to_destroy);
	free(to_destroy.comp);
	free(to_destroy.valid);
}

void			free_game_engine(t_game_engine *to_free)
{
	destroy_game_engine(*to_free);
	free(to_free);
}
