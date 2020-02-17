#include "cub3d.h"

t_tile create_tile(t_tile_type p_type, t_color p_ceiling, t_color p_floor)
{
	t_tile result;

	result.type = p_type;
	result.ceiling = p_ceiling;
	result.floor = p_floor;
	result.texture = malloc(sizeof(t_image *) * 4);
	if (result.texture == NULL)
		error_exit(1, "Can't malloc a t_image *");
	return (result);
}

t_tile *malloc_tile(t_tile_type p_type, t_color p_ceiling, t_color p_floor)
{
	t_tile *result;

	result = (t_tile *)malloc(sizeof(t_tile));
	if (result == NULL)
		return (NULL);
	*result = create_tile(p_type, p_ceiling, p_floor);
	return (result);
}

void 	destroy_tile(t_tile to_destroy)
{
	//do with the parsing
}

void 	free_tile(t_tile *to_free)
{
	//do with the parsing
}

void set_tile_texture(t_tile *tile, t_direction dir, t_image *p_image)
{
	tile->texture[(int)(dir)] = p_image;
}
