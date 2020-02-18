#include "cub3d.h"

#define FOV 70.0f
#ifndef M_PI
   #define M_PI 3.14159265358979323846f
#endif

float degree_to_radian(float degree)
{
	return ((degree * M_PI) / 180.0f);
}

float radian_to_degree(float radian)
{
	return ((radian * 180.0f) / M_PI);
}

/*

|       x
|	   /
|     r
|	 /
|	o
o-----------

*/

t_vector2	get_contact_pos(t_vector2 pos, t_vector2 target)
{
	t_vector2 tmp_pos;
	t_vector2 tmp_target;
	t_vector2 result;

	tmp_pos = substract_vector2_to_vector2(pos, pos);
	tmp_target = substract_vector2_to_vector2(target, pos);
	return (result);
}

void *calc_detection(t_map *map, t_vector2 pos)
{
	int x;
	int y;

	x = (int)(pos.x);
	y = (int)(pos.y);
	if (map->board[x][y]->type == wall)
		return (map->board[x][y]);
	return (NULL);
}

/*
		/|
|    1 / |  y
|     /  |
|	 / alpha
|   x----+
|	   x
o-----------

a = adjacent
o = oppose
h = hypothenuse

SOH/CAH/TOA
sin -> on a o et h / cos -> on a a et h / tan -> on a o a

x = cos(alpha)
y = sin(alpha)

*/

t_vector2 cast_ray(t_map *map, t_vector2 actual, float angle)
{
	t_vector2 delta;
	void *hit;
	float radian;

	radian = degree_to_radian(angle);
	delta = create_vector2f(cos(radian), sin(radian));
	hit = NULL;
	while (	hit == NULL &&
			actual.x >= 0 && actual.x < map->size.x &&
			actual.y >= 0 && actual.y < map->size.y)
	{
		actual = add_vector2_to_vector2(actual, delta);
		hit = calc_detection(map, actual);
	}
	printf("Wall hit at angle %f = %d / %d\n", angle, (int)(actual.x), (int)(actual.y));
	return (actual);
}

int draw_map(void *param)
{
	t_game_engine *engine;

	engine = (t_game_engine *)(param);

	clear_application(create_color(50, 50, 50, 255));

	draw_rectangle(create_vector2(0, 0), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->ceiling));
	draw_rectangle(create_vector2(0, g_app->size.y / 2), create_vector2(g_app->size.x, g_app->size.y / 2), *(engine->floor));

	float angle_begin;
	float angle_delta;
	float angle_actual;
	size_t i;

	angle_begin = engine->player->angle + FOV / 2;
	angle_delta = FOV / g_app->size.x;

	printf("---=====---\n");
	i = 0;
	while (i < g_app->size.x)
	{
		angle_actual = angle_begin - angle_delta * i;
		cast_ray(engine->map, engine->player->pos, angle_actual);
		i++;
	}

	render_application();

	return (1);
}

int main()
{
	t_game_engine engine;
	t_vector2 resolution;

	start_application(100, 100, "Cub3D (c)");

	int fd = open("map.cub", O_RDONLY);
	if (fd < 3)
		error_exit(1, "Bad file !");

	engine = create_game_engine();
	parse_game_engine(&engine, fd, &resolution);
	parse_map(&engine, fd);

	// draw_minimap(engine.map);
	// ft_printf("Player at %v / %d\n", engine.player->pos, (int)(engine.player->angle));
	resize_application((int)(resolution.x), (int)(resolution.y));

	add_interaction_to_application(KEYPRESS, handle_key, NULL);

	render_funct_application(&draw_map, &engine);

	return (run_application());
}
