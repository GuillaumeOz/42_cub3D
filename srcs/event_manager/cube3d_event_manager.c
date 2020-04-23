/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_event_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 18:45:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	void	key_loader(int key, t_player *player, int32_t *control,
	 void *param)
{
	if (key == ESC_KEY)
		close_application();
	else if (key == LSFT_KEY)
		*control = (*control | BONUS_SPEEDUP_KEYPRESS) | SPEED_MARKER;
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
	else if ((key == NKMN_KEY || key == NKPL_KEY) && player->hp > 0)
		player->hp += key == NKMN_KEY ? -10 : 10;
	else if ((key == RSFT_KEY) && player->hp > 0)
		*control = (*control | FIRE_KEYPRESS) | FIRE_MAKER;
	else if (key == RTN_KEY && player->hp <= 0)
		load_map_control(*control, param);
	else if (key == F_KEY && !(*control & INTERACT_MAKER))
		*control = (*control | INTERACT_KEYPRESS) | INTERACT_MAKER;
}

static void player_marker_remover(int key, int32_t *control)
{
	if (key == W_KEY)
		*control = (*control ^ W_KEYPRESS);
	else if (key == A_KEY)
		*control = (*control ^ A_KEYPRESS);
	else if (key == S_KEY)
		*control = (*control ^ S_KEYPRESS);
	else if (key == D_KEY)
		*control = (*control ^ D_KEYPRESS);
	else
		*control = (*control ^ PLAYER_MARKER);
}

int			cube3d_key_press_manager(int key, void *param)
{
	t_game_engine	*engine;
	t_player		*player;
	int32_t			*control;

	engine = (t_game_engine*)param;
	player = (t_player*)engine->player;
	control = (int32_t*)&engine->player->control;
	control = NOEVENTMASK;
	key_loader(key, player, control, param);
	return(control != NOEVENTMASK ? true : false);
}

int cube3d_key_release_manager(int key, void *param)
{
	t_game_engine	*engine;
	int32_t			*control;

	engine = (t_game_engine*)param;
	control = (int32_t*)&engine->player->control;
	if (*control & PLAYER_MARKER)
		player_marker_remover(key, control);
	else if (key == LEFT_KEY)
		*control = (*control ^ LEFT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RIGHT_KEY || key == E_KEY)
		*control = (*control ^ RIGHT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RSFT_KEY)
		*control = (*control ^ FIRE_KEYPRESS) ^ FIRE_MAKER;
	else if (key == F_KEY)
		*control = (*control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
	else if (key == LSFT_KEY)
		*control = (*control ^ BONUS_SPEEDUP_KEYPRESS) ^ SPEED_MARKER;
	return(control == NOEVENTMASK ? true : false);
}
