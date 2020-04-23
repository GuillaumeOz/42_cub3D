/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:29:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 18:43:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		fire_control(int32_t control, void *param)
{
	t_game_engine	*en;
	t_player		*hero;
	int	range;

	en = (t_game_engine*)param;
	hero = (t_player*)en->player;
	(void)control;
	range = 0;
	while (++range <= 3)
	{
		if (en->map->board[(int)(hero->pos.y + (hero->movement.y * range)) /
		(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x * range)) /
		(int)(hero->size)]->type == monster)
		{
			en->map->board[(int)(hero->pos.y + (hero->movement.y * range)) /
			(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x *
			range)) / (int)(hero->size)]->type = dead_monster;
			break ;
		}
		else if (!(ft_ischar(en->map->comp, en->map->board[(int)(hero->pos.y +
		(hero->movement.y * range)) / (int)(hero->size)]
		[(int)(hero->pos.x + (hero->movement.x * range)) /
		(int)(hero->size)]->type == SUCCESS)))//check if there are any probs with ischar
			return ;
	}
}

void    camera_control(int32_t control, void* param)
{
	t_game_engine	*modifier;
	t_player		*player;
	float			x;
	float			y;

	modifier = (t_game_engine*)param;
	player = (t_player*)modifier->player;
	x = player->forward.x;
	y = player->forward.y;
	if (control & LEFT_KEYPRESS)
	{
		player->angle -= 10;
		player->forward.y = x * sin(degree_to_radian(-10)) + y * cos(degree_to_radian(-10));
		player->forward.x = x * cos(degree_to_radian(-10)) - y * sin(degree_to_radian(-10));
	}
	else if (control & RIGHT_KEYPRESS)
	{
		player->angle += 10;
		player->forward.y = x * sin(degree_to_radian(10)) + y * cos(degree_to_radian(10));
		player->forward.x = x * cos(degree_to_radian(10)) - y * sin(degree_to_radian(10));
	}
	player->right.y = player->forward.x;
	player->right.x = -player->forward.y;
}

void		interact_control(int32_t control, void* param)
{
	t_game_engine	*engine;
	t_player		*hero;
	t_map			*map;

	engine = (t_game_engine*)param;
	hero = (t_player*)engine->player;
	map = (t_map*)engine->map;
	(void)control;
	condition_interact(engine, map, hero);
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
}

void    player_control(int32_t control, void *param)
{
	t_game_engine	*modifier;
	t_player		*player;
	t_map			*map;

	modifier = (t_game_engine*)param;
	player = (t_player*)modifier->player;
	map = (t_map*)modifier->map;
	if (control & W_KEYPRESS)
		player_hitbox(map, &player->pos, player->forward, player->speed);
	if (control & A_KEYPRESS)
		player_hitbox(map, &player->pos, create_vector2(-player->right.x,
			-player->right.y), player->speed);
	if (control & D_KEYPRESS)
		player_hitbox(map, &player->pos, player->right, player->speed);
	if (control & S_KEYPRESS)
		player_hitbox(map, &player->pos, create_vector2(-player->forward.x,
			-player->forward.y), player->speed);
	player->speed = 1.0f;
}

void    speed_control(int32_t control, void* param)
{
	t_game_engine	*modifier;
	t_player		*player;

	modifier = (t_game_engine*)param;
	player = (t_player*)modifier->player;
	if (control & BONUS_SPEEDUP_KEYPRESS)
		player->speed = 1.2f;
}
