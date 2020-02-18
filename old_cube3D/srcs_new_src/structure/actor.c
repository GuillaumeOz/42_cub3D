#include "cub3d.h"

t_actor		create_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir)
{
	t_actor result;

	result.pos = p_pos;
	result.team = p_team;
	result.angle = (90 * (int)(p_dir));
	return (result);
}

t_actor		*malloc_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir)
{
	t_actor *result;

	result = (t_actor *)malloc(sizeof(t_actor));
	if (result == NULL)
		return (NULL);
	*result = create_actor(p_pos, p_team, p_dir);
	return (result);
}

t_enemy		create_enemy(t_vector2 p_pos)
{
	return (create_actor(p_pos, enemy, north));
}

t_enemy		*malloc_enemy(t_vector2 p_pos)
{
	return (malloc_actor(p_pos, enemy, north));
}

t_player	create_player(t_vector2 p_pos, t_direction p_dir)
{
	return (create_actor(p_pos, ally, p_dir));
}

t_player	*malloc_player(t_vector2 p_pos, t_direction p_dir)
{
	return (malloc_actor(p_pos, ally, p_dir));
}

t_actor		create_neutral(t_vector2 p_pos)
{
	return (create_actor(p_pos, neutral, north));
}

t_actor		*malloc_neutral(t_vector2 p_pos)
{
	return (malloc_actor(p_pos, neutral, north));
}

void		destroy_actor(t_actor to_destroy)
{
	(void)to_destroy;
}

void		free_actor(t_actor *to_free)
{
	destroy_actor(*to_free);
	free(to_free);
}
