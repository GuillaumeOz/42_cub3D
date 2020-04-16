/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_key_press_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/16 19:44:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_cube3d_key_handler g_cube3d_key_handler [] =
{
	{ SPEEDBONUS, &speed_control},
	{ CAMERACONTRL, &camera_control},
	{ PLAYERCONTRL, &player_control},
	{ FIRECONTRL, &fire_control},
	{ INTERACT_MAKER, &load_map_control},
	{ NOCONTRL, NULL}
};

static	bool	hit_player_wall(t_map *map, t_vector2 pos)
{
	int x;
	int y;

	x = (int)(pos.x);
	y = (int)(pos.y);
	if (map->board[x][y]->type == wall)
		return (true);
	return (false);
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

void	player_hitbox(t_map *map, t_vector2 *pos, t_vector2 mov, float speed)
{
	float dot;
	float y;
	float x;

	dot = 0.1f;
	x = mov.x * speed;
	while (hit_player_wall(map, create_vector2(pos->x + x - dot, pos->y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + x + dot, pos->y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + x - dot, pos->y - dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + x + dot, pos->y - dot)) == true)
			x += x < 0 ? 0.1f: -0.1f;
	y = mov.y * speed;
	while (hit_player_wall(map, create_vector2(pos->x - dot, pos->y + y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + dot, pos->y + y + dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x - dot, pos->y + y - dot)) == true ||
		hit_player_wall(map, create_vector2(pos->x + dot, pos->y + y - dot)) == true)
			y += y < 0 ? 0.1f: -0.1f;
	*pos = add_vector2_to_vector2(*pos, create_vector2(x, y));
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

static	void	key_loader(int key, t_player *player, int32_t *control)
{
	if (key == ESC_KEY)
		close_application();
	else if (key == LSFT_KEY)
		*control = (*control | BONUS_SPEEDUP_KEYPRESS) | SPEEDBONUS;
	else if (key == W_KEY)
		*control = (*control | W_KEYPRESS) | PLAYER_MARKER;
	else if (key == A_KEY)
		*control = (*control | A_KEYPRESS) | PLAYER_MARKER;
	else if (key == S_KEY)
		*control = (*control | S_KEYPRESS) | PLAYER_MARKER;
	else if (key == D_KEY)
		*control = (*control | D_KEYPRESS) | PLAYER_MARKER;
	else if (key == LEFT_KEY)
		*control = (*control | LEFT_KEYPRESS) | CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		*control = (*control | RIGHT_KEYPRESS) | CAMERA_MARKER;
	else if (key == NKMN_KEY && player->hp > 0)
		player->hp += -10;
	else if (key == NKPL_KEY && player->hp > 0)
		player->hp += 10;
	else if ((key == LSFT_KEY || key == RSFT_KEY) && player->hp > 0)
		*control = (*control | FIRE_KEYPRESS) | FIRE_MAKER;
	else if (key == RTN_KEY && player->hp <= 0)
	{
		player->hp = 100;// add this in the fonction load_map
		*control = (*control | FIRE_KEYPRESS) | FIRE_MAKER;
	}
	else if (key == F_KEY && !(*control & INTERACT_MAKER))
		*control = (*control | INTERACT_KEYPRESS) | INTERACT_MAKER;
}

int			cube3d_key_press_manager(int key, void *param)
{
	t_game_engine	*engine;
	t_player		*player;
	int32_t			control;
	int				i;

	engine = (t_game_engine*)engine;
	player = (t_player*)engine->player;
	control = (int32_t)engine->player->control;
	control = NOEVENTMASK;
	i = -1;
	key_loader(key, player, &control);
	while (g_cube3d_key_handler[++i].marker_control != NOCONTRL)
		if (control & g_cube3d_key_handler[i].marker_control)
			g_cube3d_key_handler[i].controler(control, param);
	return(control != NOEVENTMASK ? true : false);
}
