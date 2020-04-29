/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:29:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/29 19:41:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		fire_control(int32_t control, void *param)
{
	t_player		*hero;
	t_map			*map;
	int				range;

	(void)control;
	hero = (t_player*)(((void**)param)[1]);
	map = (t_map*)(((void**)param)[0]);
	range = 0;
	while (++range <= 3)
	{
		if (map->board[(int)(hero->pos.y + (hero->movement.y * range)) /
		(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x * range)) /
		(int)(hero->size)]->type == monster)
		{
			map->board[(int)(hero->pos.y + (hero->movement.y * range)) /
			(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x *
			range)) / (int)(hero->size)]->type = dead_monster;
			break ;
		}
		else if ((comp_type_check(map->comp, map->board[(int)(hero->pos.y +
		(hero->movement.y * range)) / (int)(hero->size)]
		[(int)(hero->pos.x + (hero->movement.x * range)) /
		(int)(hero->size)]) == false))
			return ;
	}
}

void    camera_control(int32_t control, void* param)
{
	t_player	*hero;
	
	hero = (t_player*)(((void**)param)[1]);
	if (control & LEFT_KEYPRESS)
		hero->pitch += hero->rotation_speed;
	if (control & RIGHT_KEYPRESS)
		hero->pitch -= hero->rotation_speed;
	control = (control ^ CAMERA_MARKER);
}

void		interact_control(int32_t control, void* param)
{
	t_game_engine	*engine;
	t_player		*hero;
	t_map			*map;

	(void)control;
	condition_interact(param, engine, map, hero);//redo this part
	engine = (t_game_engine*)(((void**)param)[2]);
	hero = (t_player*)(((void**)param)[1]);
	map = (t_map*)(((void**)param)[0]);
	if (map->board[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)]->type == monster)
	{
		hero->hp -= engine->monster.damage;
		map->board[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)]->type = dead_monster;
	}
	if (map->board[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)]->type == medikit &&
		hero->hp < 100)
	{
		hero->hp += engine->medikit.heal;
		map->board[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)]->type = empty;
	}
	hero->control = (hero->control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
}

void    player_control(int32_t control, void *param)
{
	t_player		*hero;
	t_map			*map;

	hero = (t_player*)(((void**)param)[1]);
	map = (t_map*)(((void**)param)[0]);
	if (control & W_KEYPRESS)
		player_hitbox(hero, hero->movement, *map, 1);
	if (control & A_KEYPRESS)
		player_hitbox(hero, hero->last_movement, *map, -1);
	if (control & D_KEYPRESS)
		player_hitbox(hero, hero->last_movement, *map, 1);
	if (control & S_KEYPRESS)
		player_hitbox(hero, hero->movement, *map, -1);
}

void    speed_control(int32_t control, void* param)
{
	t_player		*hero;

	hero = (t_player*)(((void**)param)[1]);
	if (control & BONUS_SPEEDUP_KEYPRESS)
		hero->bonus_speed = 2.5f;
}
