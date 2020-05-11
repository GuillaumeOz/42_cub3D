/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:41:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 16:00:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_save(t_game_engine *engine, char *save_arg)
{
	if (ft_strcmp(save_arg, "--save") == 0)
		engine->save = true;
	else
		catch_error(CHECK_SAVE_1);
}

static void	set_empty_wall_tile(t_game_engine *engine)
{
	engine->wall_tile = malloc_tile(*engine, wall);
	engine->empty_tile = malloc_tile(*engine, empty);
	engine->sprite_tile = malloc_tile(*engine, sprite);
	engine->door_tile = malloc_tile(*engine, door);
	engine->closed_door_tile = malloc_tile(*engine, closed_door);
	engine->secret_tile = malloc_tile(*engine, secret);
	engine->dead_tile = malloc_tile(*engine, dead_monster);
	engine->medikit_tile = malloc_tile(*engine, medikit);
	engine->monster_tile = malloc_tile(*engine, monster);
}

static void	check_mapname(char *map_name)
{
	int i;

	i = 0;
	while (map_name[i])
		i++;
	if (i < 5)
		catch_error(CHECK_MAPNAME_1);
	i -= 4;
	if ((ft_strcmp(map_name + i, ".cub")) != 0)
		catch_error(CHECK_MAPNAME_1);
}

void		cub3d_parsing(t_game_engine *engine, int argc, char **argv,
	t_vector2 *resolution)
{
	int fd;

	if (argc == 3)
		check_save(engine, argv[2]);
	check_mapname(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		catch_error(CUB3D_PARSING_1);
	parse_game_engine(engine, fd, resolution);
	engine->resolution = *(resolution);
	set_empty_wall_tile(engine);
	parse_map(engine, fd);
	if (engine->player == NULL)
		catch_error(CUB3D_PARSING_2);
	set_player_status(engine->player, engine->map);
	close(fd);
}
