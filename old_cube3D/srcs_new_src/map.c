#include "cub3d.h"

t_tile ***malloc_tile_tab(t_vector2 size)
{
	t_tile ***result;
	size_t i;

	result = malloc(sizeof(t_tile **) * size.x);
	if (result == NULL)
		error_exit(1, "Can't malloc a t_tile **");
	i = 0;
	while (i < size.x)
	{
		result[i] = malloc(sizeof(t_tile *) * size.y);
		if (result[i] == NULL)
			error_exit(1, "Can't malloc a t_tile *");
		i++;
	}
	return (result);
}

t_map create_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content)
{
	size_t i;
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
					error_exit(1, "Multiple player on the map");
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

t_map *malloc_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content)
{
	t_map *result;

	result = (t_map *)malloc(sizeof(t_map));
	if (result == NULL)
		return (NULL);
	*result = create_map(engine, p_size, p_content);
	return (result);
}

void draw_minimap(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			ft_printf("%c", (map->board[j][i]->type == wall ? 'X' : ' '));
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
