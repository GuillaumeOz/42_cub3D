/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:38:12 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/21 17:24:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_game_engine	*malloc_game_engine(void)
{
	t_game_engine *result;

	result = (t_game_engine*)malloc(sizeof(t_game_engine));
	if (result == NULL)
		catch_error(CREATE_GAME_ENGINE_1);
	*result = create_game_engine();
	return (result);
}

t_game_engine	create_game_engine(void)
{
	t_game_engine result;

	result.resolution = create_vector2(0, 0);
	result.texture = (t_texture **)malloc(sizeof(t_texture*) * 4);
	if (result.texture == NULL)
		catch_error(CREATE_GAME_ENGINE_2);
	result.sprite = malloc_texture(NULL);
	result.door = create_texture(NULL);
	result.ceiling = NULL;
	result.floor = NULL;
	result.empty_tile = NULL;
	result.wall_tile = NULL;
	result.map_content = malloc_list(500);
	result.map = NULL;
	result.player = NULL;
	result.monster = create_monster(NULL, NULL, 0);
	result.medikit = create_medikit(NULL, 0);
	result.comp = ft_strdup("0DMmH2");
	result.valid = ft_strdup(" 012SNEW");
	result.save = false;
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
	free(to_destroy.comp);
	free(to_destroy.valid);
}

void 			free_game_engine(t_game_engine *to_free)
{
	destroy_game_engine(*to_free);
	free(to_free);
}
