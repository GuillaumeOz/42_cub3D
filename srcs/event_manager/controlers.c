/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:29:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/17 20:21:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	load_map_control(int32_t control, void *param)
{
    t_game_engine   *engine;
	char            *arg;
	char            num[2];

    engine = (t_game_engine*)param;
    engine->player->hp = 100;
	*(engine->player) = reset_player(engine->player->hp);
	num[0] = map->level + 1;
	num[1] = '\0';
	write(1, "level :", 7);
	write(1, num, 1);
	write(1, "\n", 1);
	num[0] = map->level;
	arg = ft_strjoin("maps/start", num);
	arg = ft_strjoin(arg, ".cub");
	cub3d_get_param(map, arg);
	map->resolution = g_app->size;
	cub3d_parse_map(map, hero);
	hero->size = (int)((map->resolution.y * 0.33) / (map->size.y));
	if (hero->size > (int)((map->resolution.x * 0.27) / (map->size.x)))
		hero->size = (int)((map->resolution.x * 0.27) / (map->size.x));
	hero->radius *= hero->size;
	hero->pos.x = (hero->pos.x * hero->size) - (hero->size / 2);
	hero->pos.y = (hero->pos.y * hero->size) + (hero->size / 2);
}

void		fire_control(t_map *map, t_player *hero)
{
	int	range;

	range = 1;
	if (hero->fire == true)
	{
		while (range <= 3)
		{
			if (map->map[(int)(hero->pos.y + (hero->movement.y * range)) /
			(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x * range)) /
			(int)(hero->size)] == 'M')
			{
				map->map[(int)(hero->pos.y + (hero->movement.y * range)) /
				(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x *
				range)) / (int)(hero->size)] = 'm';
				break ;
			}
			else if (!(comp_char(map->comp, map->map[(int)(hero->pos.y +
				(hero->movement.y * range)) / (int)(hero->size)]
				[(int)(hero->pos.x + (hero->movement.x * range)) /
				(int)(hero->size)])))
				return ;
			range++;
		}
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
	if (control & RIGHT_KEYPRESS)
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
	t_game_engine *engine;

	engine = (t_game_engine*)param;
	if (hero->interact == true)
		condition_interact(map, hero);
	if (map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] == 'M')
	{
		hero->hp -= map->monster.damage;
		map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] = 'm';
	}
	if (map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] == 'H' && hero->hp < 100)
	{
		hero->hp += map->medikit.heal;
		map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] = '0';
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
