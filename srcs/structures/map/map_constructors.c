/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:12:59 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 21:05:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*malloc_map(t_game_engine *engine, t_vector2 p_size,
	t_list *p_content)
{
	t_map	*result;

	result = (t_map*)malloc(sizeof(t_map));
	if (result == NULL)
		catch_error(MALLOC_MAP_1);
	*result = create_map(engine, p_size, p_content);
	return (result);
}

t_tile		***malloc_tile_tab(t_vector2 size)
{
	t_tile ***result;
	size_t i;

	result = (t_tile***)malloc(sizeof(t_tile **) * size.y);
	if (result == NULL)
		catch_error(MALLOC_TILE_TAB_1);
	i = 0;
	while (i < size.y)
	{
		result[i] = (t_tile **)malloc(sizeof(t_tile *) * size.x);
		if (result[i] == NULL)
			catch_error(MALLOC_TILE_TAB_2);
		i++;
	}
	return (result);
}

static void	create_map_3(t_game_engine *engine, t_map *result,
	char *line, t_vector2 pos)
{
	if (line[(int)pos.x] == '3')
		result->board[(int)pos.y][(int)pos.x] = engine->door_tile;
	else if (line[(int)pos.x] == '4')
		result->board[(int)pos.y][(int)pos.x] = engine->secret_tile;
	else if (line[(int)pos.x] == 'H')
		result->board[(int)pos.y][(int)pos.x] = engine->medikit_tile;
	else if (line[(int)pos.x] == 'M')
		result->board[(int)pos.y][(int)pos.x] = engine->monster_tile;
}

static void	create_map_2(t_game_engine *engine, t_map *result,
	char *line, t_vector2 pos)
{
	if (line[(int)pos.x] == '2')
		result->board[(int)pos.y][(int)pos.x] = engine->sprite_tile;
	else if (line[(int)pos.x] == 'W' || line[(int)pos.x] == 'E' ||
		line[(int)pos.x] == 'S' || line[(int)pos.x] == 'N')
	{
		result->board[(int)pos.y][(int)pos.x] = engine->empty_tile;
		if (engine->player != NULL)
			catch_error(CREATE_MAP_2);
		if (line[(int)pos.x] == 'W')
			engine->player = malloc_player(create_vector2(pos.x, pos.y),
				PI, PLAYER_SPEED);
		if (line[(int)pos.x] == 'E')
			engine->player = malloc_player(create_vector2(pos.x, pos.y),
				0, PLAYER_SPEED);
		if (line[(int)pos.x] == 'S')
			engine->player = malloc_player(create_vector2(pos.x, pos.y),
				(-PI / 2), PLAYER_SPEED);
		if (line[(int)pos.x] == 'N')
			engine->player = malloc_player(create_vector2(pos.x, pos.y),
				(PI / 2), PLAYER_SPEED);
	}
	else
		create_map_3(engine, result, line, pos);
}

t_map		create_map(t_game_engine *engine, t_vector2 p_size,
	t_list *p_content)
{
	t_map	result;
	char	*line;
	int		i;
	int		j;

	result.size = p_size;
	result.comp = engine->comp;
	result.valid = engine->valid;
	result.resolution = engine->resolution;
	result.board = malloc_tile_tab(p_size);
	i = -1;
	while (++i < result.size.y)
	{
		line = list_at(p_content, i);
		j = -1;
		while (++j < result.size.x)
			if (line[j] == '1')
				result.board[i][j] = engine->wall_tile;
			else if (line[j] == '0' || line[j] == ' ')
				result.board[i][j] = engine->empty_tile;
			else
				create_map_2(engine, &result, line, create_vector2(j, i));
	}
	return (result);
}
