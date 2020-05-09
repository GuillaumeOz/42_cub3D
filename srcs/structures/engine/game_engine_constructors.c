/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_constructors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:25:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 20:34:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game_engine	*malloc_game_engine(void)
{
	t_game_engine *result;

	result = (t_game_engine*)malloc(sizeof(t_game_engine));
	if (result == NULL)
		catch_error(MALLOC_GAME_ENGINE_1);
	*result = create_game_engine();
	return (result);
}

static void		engine_tile_set(t_game_engine *result)
{
	result->empty_tile = NULL;
	result->wall_tile = NULL;
	result->sprite_tile = NULL;
	result->door_tile = NULL;
	result->closed_door_tile = NULL;
	result->secret_tile = NULL;
	result->dead_tile = NULL;
	result->medikit_tile = NULL;
	result->monster_tile = NULL;
}

static void		engine_texture_set(t_game_engine *result)
{
	result->texture = (t_texture**)malloc(sizeof(t_texture*) * 4);
	if (result->texture == NULL)
		catch_error(ENGINE_TEXTURE_SET_1);
	result->texture[west] = NULL;
	result->texture[north] = NULL;
	result->texture[east] = NULL;
	result->texture[south] = NULL;
}

t_game_engine	create_game_engine(void)
{
	t_game_engine result;

	result.resolution = create_vector2(0, 0);
	engine_texture_set(&result);
	result.sprite = NULL;
	result.door = create_texture(NULL);
	result.secret = create_texture(NULL);
	result.ceiling = NULL;
	result.floor = NULL;
	engine_tile_set(&result);
	result.map_content = malloc_list(500);
	result.map = NULL;
	result.player = NULL;
	result.monster = create_monster(NULL, NULL, 0);
	result.medikit = create_medikit(NULL, 0);
	result.comp = ft_strdup("0DMmH2");
	result.valid = ft_strdup(" 012SNEW");
	result.thread = false;
	result.save = false;
	return (result);
}
