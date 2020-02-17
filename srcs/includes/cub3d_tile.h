#ifndef CUB3D_TILE_H
#define CUB3D_TILE_H

typedef enum	e_direction
{
	east = 0,
	north = 1,
	west = 2,
	south = 3
}				t_direction;

typedef enum e_tile_type
{
	empty = 0,
	wall = 1
}				t_tile_type;

typedef struct s_tile
{
	t_tile_type type;
	t_color		ceiling;
	t_color		floor;
	t_image		**texture;
}				t_tile;

t_tile	create_tile(t_tile_type p_type, t_color p_ceiling, t_color p_floor);
t_tile	*malloc_tile(t_tile_type p_type, t_color p_ceiling, t_color p_floor);
void 	destroy_tile(t_tile to_destroy);
void 	free_tile(t_tile *to_free);

void set_tile_texture(t_tile *tile, t_direction dir, t_image *p_image);

#endif
