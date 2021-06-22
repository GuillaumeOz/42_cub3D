/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:13:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:05:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_engine	*malloc_engine(void)
{
	t_engine	*engine;

	engine = (t_engine *)malloc(sizeof(t_engine));
	if (engine == NULL)
		cub3d_error(ERROR_ENGINE1, "t_engine can't be malloc");
	*engine = create_engine();
	return (engine);
}

t_engine	create_engine(void)
{
	t_engine	engine;

	engine.app = start_application(500, 500, "Cub3D");
	engine.resolution = create_int_vector2(500, 500);
	set_engine_texture(&engine);
	engine.texture[NORTH] = NULL;
	engine.texture[SOUTH] = NULL;
	engine.texture[EAST] = NULL;
	engine.texture[WEST] = NULL;
	engine.sprite_basic = NULL;
	engine.sprite_list = malloc_list(10);
	engine.floor = NULL;
	engine.ceiling = NULL;
	engine.floor_texture = NULL;
	engine.ceiling_texture = NULL;
	engine.secret_door = NULL;
	engine.player = NULL;
	engine.map = malloc_list(50);
	engine.wall_limit = NULL;
	set_engine_wall_limit(&engine);
	engine.allow_charset = NULL;
	set_allow_charset(&engine, " 01NSEW");
	engine.sprites_num = 0;
	engine.bonus = NO_BONUS;
	return (engine);
}

void	destroy_engine(t_engine to_destroy)
{
	free_texture(to_destroy.texture[NORTH]);
	free_texture(to_destroy.texture[SOUTH]);
	free_texture(to_destroy.texture[EAST]);
	free_texture(to_destroy.texture[WEST]);
	free(to_destroy.texture);
	if (to_destroy.sprite_basic != NULL)
		free_sprite(to_destroy.sprite_basic);
	free_list(to_destroy.sprite_list, &free);
	free_color(to_destroy.floor);
	free_color(to_destroy.ceiling);
	if (to_destroy.floor_texture != NULL)
		free_texture(to_destroy.floor_texture);
	if (to_destroy.ceiling_texture != NULL)
		free_texture(to_destroy.ceiling_texture);
	if (to_destroy.secret_door != NULL)
		free_texture(to_destroy.secret_door);
	free_player(to_destroy.player);
	free_list(to_destroy.map, &free);
	free(to_destroy.wall_limit);
	free(to_destroy.allow_charset);
	close_application(to_destroy.app);
}

void	free_engine(t_engine *to_free)
{
	destroy_engine(*to_free);
	free(to_free);
}
