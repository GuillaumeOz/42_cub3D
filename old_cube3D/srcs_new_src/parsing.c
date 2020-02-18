#include "cub3d.h"

bool parse_environement_texture(t_game_engine *engine, char *descriptor, char *content)
{
	if (ft_strcmp(descriptor, "WE") == 0)
		return (set_texture_image(engine, west, content));
	else if (ft_strcmp(descriptor, "NO") == 0)
		return (set_texture_image(engine, north, content));
	else if (ft_strcmp(descriptor, "EA") == 0)
		return (set_texture_image(engine, east, content));
	else if (ft_strcmp(descriptor, "SO") == 0)
		return (set_texture_image(engine, south, content));
	else if (ft_strcmp(descriptor, "S") == 0)
		return (set_sprite_image(engine, content));
	else
		return (false);
}

bool parse_environement_color(t_game_engine *engine, char *descriptor, char *content)
{
	if (ft_strcmp(descriptor, "C") == 0)
		return (set_color_type(engine, CEILING, content));
	else if (ft_strcmp(descriptor, "F") == 0)
		return (set_color_type(engine, FLOOR, content));
	else
		return (false);
}

bool parse_resolution(char *descriptor, char *content, t_vector2 *resolution)
{
	char **tab;
	size_t i;

	if (ft_strcmp(descriptor, "R") == 0)
	{
		tab = ft_strsplit(content, ' ');
		if (ft_tab_len(tab) != 2)
			error_exit(1, "Bad number of arguments for resolution");
		i = 0;
		while (tab[i] != NULL)
		{
			if (ft_strisdigit(tab[i]) == false)
				error_exit(1, ft_eprintf("%s with value [%s]\n", "Arguments invalid for resolution", tab[i]));
			i++;
		}
		*resolution = create_vector2(ft_atoi(tab[0]), ft_atoi(tab[1]));
		ft_tab_free(tab);
		return (true);
	}
	else
		return (false);
}

void parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution)
{
	size_t i;
	size_t j;
	char *descriptor;
	char *content;

	i = 0;
	content = NULL;
	while (is_engine_full(engine) == false && get_next_line(fd, &content) > 0)
	{
		descriptor = ft_strcut(&content, ' ');
		j = 0;
		while (content[j] == ' ')
			j++;
		if (parse_environement_texture(engine, descriptor, &(content[j])) == true)
			;
		else if (parse_environement_color(engine, descriptor, &(content[j])) == true)
			;
		else if (parse_resolution(descriptor, &(content[j]), resolution) == true)
			;
		else if (ft_strlen(descriptor) == 0)
			;
		else
			error_exit(1, ft_eprintf("Error on line %d in the file", i));
		i++;
	}
	engine->wall_tile = malloc_tile(wall, *(engine->ceiling), *(engine->floor));
	set_tile_texture(engine->wall_tile, north, engine->texture[0]);
	set_tile_texture(engine->wall_tile, east, engine->texture[1]);
	set_tile_texture(engine->wall_tile, south, engine->texture[2]);
	set_tile_texture(engine->wall_tile, west, engine->texture[3]);
	engine->empty_tile = malloc_tile(empty, *(engine->ceiling), *(engine->floor));
}

bool parse_map_line(t_game_engine *engine, char *line, t_vector2 *map_size)
{
	char *content;

	content = ft_strdup_no_c(line, ' ');
	if (map_size->x == 0)
		map_size->x = ft_strlen(content);
	if (ft_strlen(content) != map_size->x)
		return (false);
	list_push_back(engine->map_content, content);
	map_size->y++;
	return (true);
}

void compute_map(t_game_engine *engine, t_vector2 map_size)
{
	engine->map = malloc_map(engine, map_size, engine->map_content);
}

void parse_map(t_game_engine *engine, int fd)
{
	t_vector2 map_size;
	int		i;
	bool	found;
	char	*line;

	line = NULL;
	found = false;
	map_size = create_vector2(0, 0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 0 && found == false)
			;
		else if (ft_strlen(line) != 0)
		{
			if (parse_map_line(engine, line, &map_size) == true)
				found = true;
			else
				error_exit(1, ft_eprintf("Error on line %d in the file", i));
		}
		else
			error_exit(1, ft_eprintf("Error on line %d in the file", i));
		i++;
	}
	compute_map(engine, map_size);
}
