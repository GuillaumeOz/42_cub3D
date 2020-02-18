#ifndef CUB3D_MAP_H
#define CUB3D_MAP_H

typedef struct	s_map
{
	t_vector2	size;
	t_tile		***board;
	//t_object	***content;
}				t_map;

t_map create_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content);
t_map *malloc_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content);
//destructor
void draw_minimap(t_map *map);// creat destructor and free
int draw_map(void *param);

#endif
