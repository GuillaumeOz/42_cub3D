/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:41:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/06 11:54:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		check_save(t_game_engine *engine, char *save_arg)
{
	if (ft_strcmp(save_arg, "-save") == 0)
		engine->save = true;
	else
		catch_error(CHECK_SAVE_1);
}

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

void cube3d_parsing(t_game_engine *engine, int argc, char **argv,
	t_vector2 *resolution)
{
	int fd;

	if (argc == 3)
		check_save(engine, argv[2]);
	check_mapname(argv[1]);
	fd = open(argv[1], O_RDONLY);
	parse_game_engine(engine, fd, resolution);
	//check the NULL element of struct
	set_empty_wall_tile(engine);
	parse_map(engine, fd);
}
