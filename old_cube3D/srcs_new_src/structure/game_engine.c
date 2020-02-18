#include "cub3d.h"

t_game_engine create_game_engine()
{
	t_game_engine result;

	result.texture = malloc(sizeof(t_image *) * 4);
	if (result.texture == NULL)
		error_exit(1, "Can't malloc a t_image *");
	result.sprite = NULL;

	result.ceiling = NULL;
	result.floor = NULL;

	result.empty_tile = NULL;
	result.wall_tile = NULL;

	result.map_content = malloc_list(500);
	result.map = NULL;
	return (result);
}

bool set_texture_image(t_game_engine *engine, t_direction dir, char *path)
{
	engine->texture[(int)(dir)] = load_image(path);
	return (true);
}

bool set_sprite_image(t_game_engine *engine, char *path)
{
	engine->sprite = load_image(path);
	return (true);
}

bool set_color_type(t_game_engine *engine, int type, char *content)
{
	size_t i;
	char **tab;
	t_color *color;

	if ((type == CEILING && engine->ceiling != NULL) ||
		(type == FLOOR && engine->floor != NULL))
		error_exit(1, "Color for ceiling or floor already done");
	tab = ft_strsplit(content, ',');
	if (ft_tab_len(tab) != 3)
		error_exit(1, "Bad number of arguments for a color");
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strisdigit(tab[i]) == false)
			error_exit(1, ft_eprintf("%s with value [%s]\n", "Arguments invalid for a color", tab[i]));
		i++;
	}
	color = malloc_color(
		ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]), 255);
	ft_tab_free(tab);
	if (type == CEILING)
		engine->ceiling = color;
	else if (type == FLOOR)
		engine->floor = color;
	return (true);
}

bool is_engine_full(t_game_engine *engine)
{
	if (engine->texture[0] == NULL || engine->texture[1] == NULL ||
		engine->texture[2] == NULL || engine->texture[3] == NULL ||
		engine->ceiling == NULL || engine->floor == NULL)
		return (false);
	return (true);// move into parsing part ?
}
