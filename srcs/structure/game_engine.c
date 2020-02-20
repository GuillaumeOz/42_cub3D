/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:38:12 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/20 18:23:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_game_engine	*malloc_game_engine()
{
	t_game_engine *result;

	result = (t_game_engine*)malloc(sizeof(t_game_engine));
	if (result == NULL)
		catch_error(CREATE_GAME_ENGINE_1);
	*result = create_game_engine();
	return (result);
}

t_game_engine	create_game_engine()
{
	t_game_engine result;

	result.texture = (t_image **)malloc(sizeof(t_image *) * 4);
	if (result.texture == NULL)
		catch_error(CREATE_GAME_ENGINE_2);
	result.sprite = NULL;
	result.ceiling = NULL;
	result.floor = NULL;
	result.empty_tile = NULL;
	result.wall_tile = NULL;
	result.map_content = malloc_list(500);
	result.map = NULL;
	result.player = NULL;
	return (result);
}

void 			destroy_game_engine(t_game_engine to_destroy)
{
	free_image(to_destroy.texture[0]);
	free_image(to_destroy.texture[1]);
	free_image(to_destroy.texture[2]);
	free_image(to_destroy.texture[3]);
	free_image(to_destroy.sprite);
	free_color(to_destroy.ceiling);
	free_color(to_destroy.floor);
	free_tile(to_destroy.empty_tile);
	free_tile(to_destroy.wall_tile);
	free_list(to_destroy.map_content, free);
	free_map(to_destroy.map);
	free_actor(to_destroy.player);
}

void 			free_game_engine(t_game_engine *to_free)
{
	destroy_game_engine(*to_free);
	free(to_free);
}
