/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:19:23 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 19:54:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	comp_type_check(char *str, t_tile *tile)
{
	int i;

	i = -1;
	while(str[++i])
		if (str[i] == '0' && tile->type == empty)
			return (true);
		else if (str[i] == 'D' && tile->type == door)
			return (true);
		else if (str[i] == 'M' && tile->type == monster)
			return (true);
		else if (str[i] == 'm' && tile->type == dead_monster)
			return (true);
		else if (str[i] == 'H' && tile->type == medikit)
			return (true);
		else if (str[i] == '2' && tile->type == sprite)
			return (true);
	return (false);
}

void	respawn_monster(t_game_engine *eng, t_map *map, t_player *hero)
{
	int		i;
	int		j;

	i = -1;
	debug
	while (++i < map->size.y)
	{
		while (++j < map->size.x)
			if (map->board[i][j]->type == dead_monster)
				map->board[i][j] = eng->monster_tile;
		j = -1;
	}
	hero->control = (hero->control ^ RESPAWN_KEYPRESS);
}

static void condition_interact2(t_game_engine *eng, t_map *map, t_player *hero)
{
	if (map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == secret)
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] = eng->empty_tile;
	}
	hero->control = (hero->control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
}

void	condition_interact(t_game_engine *eng, t_map *map, t_player *hero)
{
	if (hero->control & RESPAWN_KEYPRESS)
	{
		respawn_monster(eng, map, hero);
		return ;
	}
	if (map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == door)
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] = eng->closed_door_tile;
	}
	else if (map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == closed_door
		&& ((int)((hero->pos.y) / (hero->size)) != (int)((hero->pos.y +
		hero->movement.y) / (hero->size)) || (int)((hero->pos.x) /
		(hero->size)) != (int)((hero->pos.x + hero->movement.x) /
		(hero->size))))
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] = eng->door_tile;
	}
	condition_interact2(eng, map, hero);
	hero->control = (hero->control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
}

void			update_player(void *param)
{
	t_game_engine	*engine;
	t_player		*hero;
	int32_t			*control;
	int 			i;

	engine = (t_game_engine*)(((void**)param)[2]);
	hero = (t_player*)(((void**)param)[1]);
	control = (int32_t*)&engine->player->control;
    i = -1;
	if (hero->hp > 0)
	{
		hero->movement = create_vector2(hero->forward.x - hero->pos.x,
				hero->forward.y - hero->pos.y);
		hero->last_movement = create_vector2(hero->movement.x * cos(PI / 2) -
			hero->movement.y * sin(PI / 2), hero->movement.x * sin(PI / 2) +
			hero->movement.y * cos(PI / 2));
        while (g_cube3d_key_handler[++i].marker_control != NOCONTRL)
		    if (*control & g_cube3d_key_handler[i].marker_control)
		    	g_cube3d_key_handler[i].controler(*control, param);
		hero->hp = (hero->hp > 100) ? 100 : hero->hp;
	}
}
