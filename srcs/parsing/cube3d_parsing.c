/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:41:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/20 15:33:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	set_empty_wall_tile(t_game_engine *engine)
{
	engine->wall_tile = malloc_tile(wall, *(engine->ceiling), *(engine->floor));
	set_tile_texture(engine->wall_tile, north, engine->texture[0]);
	set_tile_texture(engine->wall_tile, east, engine->texture[1]);
	set_tile_texture(engine->wall_tile, south, engine->texture[2]);
	set_tile_texture(engine->wall_tile, west, engine->texture[3]);
	engine->empty_tile = malloc_tile(empty, *(engine->ceiling), *(engine->floor));
}

static void check_mapname(char *map_name)
{
	int i;

	i = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	if (map_name[i] == '\0')
		catch_error(CHECK_MAPNAME_1);
	if (map_name[i] == '.')
		if ((ft_strcmp(map_name + i, ".cub")) != 0)
			catch_error(CHECK_MAPNAME_1);
}

void cube3d_parsing(t_game_engine *engine, char *map_name, t_vector2 *resolution)
{
	int fd;

	check_mapname(map_name);
	fd = open(map_name, O_RDONLY);
	parse_game_engine(engine, fd, resolution);
	set_empty_wall_tile(engine);
	parse_map(engine, fd);
}
