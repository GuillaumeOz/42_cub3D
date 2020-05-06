/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/06 18:36:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	player_marker_remover(int key, int32_t *control)
{
	if (key == W_KEY)
		*control = (*control ^ W_KEYPRESS) ^ PLAYER_MARKER;
	else if (key == A_KEY)
		*control = (*control ^ A_KEYPRESS) ^ PLAYER_MARKER;
	else if (key == S_KEY)
		*control = (*control ^ S_KEYPRESS) ^ PLAYER_MARKER;
	else if (key == D_KEY)
		*control = (*control ^ D_KEYPRESS) ^ PLAYER_MARKER;
}

int				cube3d_key_release_manager(int key, void *param)
{
	t_player		*player;
	int32_t			*control;

	player = (t_player*)(((void**)param)[1]);
	control = (int32_t*)((int32_t*)&(player->control));
	if (key == LSFT_KEY)
	{
		*control = (*control ^ BONUS_SPEEDUP_KEYPRESS) ^ SPEED_MARKER;
		player->bonus_speed = 1.0f;
	}
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		player_marker_remover(key, control);
	else if (key == LEFT_KEY)
		*control = (*control ^ LEFT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		*control = (*control ^ RIGHT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RSFT_KEY)
		*control = (*control ^ FIRE_KEYPRESS) ^ FIRE_MAKER;
	else if (key == R_KEY)
		*control = (*control ^ RESPAWN_KEYPRESS) ^ INTERACT_MAKER;
	return (control == NOEVENTMASK ? true : false);
}

static	void	player_marker_loader(int key, int32_t *control)
{
	if (key == W_KEY)
		*control = (*control | W_KEYPRESS) | PLAYER_MARKER;
	else if (key == A_KEY)
		*control = (*control | A_KEYPRESS) | PLAYER_MARKER;
	else if (key == S_KEY)
		*control = (*control | S_KEYPRESS) | PLAYER_MARKER;
	else if (key == D_KEY)
		*control = (*control | D_KEYPRESS) | PLAYER_MARKER;
}

int				cube3d_key_press_manager(int key, void *param)
{
	t_player		*player;
	int32_t			*control;

	player = (t_player*)(((void**)param)[1]);
	control = (int32_t*)((int32_t*)&(player->control));
	if (key == ESC_KEY)
		quit(param);
	if (key == LSFT_KEY)
		*control = (*control | BONUS_SPEEDUP_KEYPRESS) | SPEED_MARKER;
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		player_marker_loader(key, control);
	else if (key == LEFT_KEY)
		*control = (*control | LEFT_KEYPRESS) | CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		*control = (*control | RIGHT_KEYPRESS) | CAMERA_MARKER;
	else if ((key == Q_KEY || key == E_KEY) && player->hp > 0)
		player->hp += key == Q_KEY ? -10 : 10;
	else if ((key == RSFT_KEY) && player->hp > 0)
		*control = (*control | FIRE_KEYPRESS) | FIRE_MAKER;
	else if (key == B_KEY && player->hp >= 0)//RNT dont work
		*control = (*control | RESPAWN_KEYPRESS) | INTERACT_MAKER;
	else if (key == F_KEY && !(*control & INTERACT_MAKER))
		*control = (*control | INTERACT_KEYPRESS) | INTERACT_MAKER;
	return(player->control != NOEVENTMASK ? true : false);
}

int				update(void *param)
{
	t_game_engine	*engine;
	t_player		*hero;
	t_map			*map;

	engine = (t_game_engine*)(((void**)param)[2]);
	hero = (t_player*)(((void**)param)[1]);
	map = (t_map*)(((void**)param)[0]);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	clear_screen();
	update_player(param);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	if (engine->thread == true)
		draw_wall_multi_thread(*hero, map);
	else if (engine->thread == false)
		draw_wall(*hero, map);
	draw_gun(*map, hero);
	draw_hud(*map);
	draw_health_bar(*map, *hero);
	draw_2d_map(map, hero);
	if (hero->hp <= 0)
		draw_game_over(*map);
	render_application();
	return (0);
}
