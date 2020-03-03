/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:10:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/02 20:35:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_map   *malloc_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content)
{
    t_map   *result;
    
	result = (t_map *)malloc(sizeof(t_map));
	if (result == NULL)
		catch_error(MALLOC_MAP_1);
	*result = create_map(engine, p_size, p_content);
	return (result);
}

t_tile ***malloc_tile_tab(t_vector2 size)
{
	t_tile ***result;
	size_t i;

	result = (t_tile***)malloc(sizeof(t_tile **) * size.x);
	if (result == NULL)
		catch_error(MALLOC_TILE_TAB_1);
	i = 0;
	while (i < size.x)
	{
		result[i] = (t_tile **)malloc(sizeof(t_tile *) * size.y);
		if (result[i] == NULL)
			catch_error(MALLOC_TILE_TAB_2);
		i++;
	}
	return (result);
}

t_map   create_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content)
{
	size_t i;//update to add the sprite (2)
	size_t j;
	t_map result;
	char *line;

	result.size = p_size;
	result.board = malloc_tile_tab(p_size);
	i = 0;
	while (i < result.size.y)
	{
		line = list_at(p_content, i);
		j = 0;
		while (j < result.size.x)
		{
			if (line[j] == '1')
				result.board[j][i] = engine->wall_tile;
			else if (line[j] == '0')
				result.board[j][i] = engine->empty_tile;
			else if (line[j] == '2')
			{
				result.board[j][i] = engine->empty_tile;
			}
			else if (line[j] == 'W' || line[j] == 'E' || line[j] == 'S' || line[j] == 'N')
			{
				result.board[j][i] = engine->empty_tile;
				if (engine->player != NULL)
					catch_error(CREATE_MAP_1);
				if (line[j] == 'W')
					engine->player = malloc_player(create_vector2(j, i), west);
				if (line[j] == 'E')
					engine->player = malloc_player(create_vector2(j, i), east);
				if (line[j] == 'S')
					engine->player = malloc_player(create_vector2(j, i), south);
				if (line[j] == 'N')
					engine->player = malloc_player(create_vector2(j, i), north);
			}
			j++;
		}
		i++;
	}
	return (result);
}

void   destroy_map(t_map to_destroy)
{
	int	i;

	i = -1;
	while (++i < to_destroy.size.x)
			free(to_destroy.board[i]);
	free(to_destroy.board);
	free_vector2(&to_destroy.size);

}

void   free_map(t_map *to_free)
{
	destroy_map(*to_free);
	free(to_free);
}
