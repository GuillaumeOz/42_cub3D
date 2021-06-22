/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:22:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 21:37:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	secret_door_remover_bonus(int key, t_player *player)
{
	if (key == E_KEY)
		player->control = (player->control ^ E_CTRL) ^ ACTION_MARKER;
	else if (key == Q_KEY)
		player->control = (player->control ^ Q_CTRL) ^ ACTION_MARKER;
}

static void	player_move_remover(int key, t_player *player)
{
	if (key == W_KEY)
		player->control = (player->control ^ W_CTRL);
	else if (key == A_KEY)
		player->control = (player->control ^ A_CTRL);
	else if (key == S_KEY)
		player->control = (player->control ^ S_CTRL);
	else if (key == D_KEY)
		player->control = (player->control ^ D_CTRL);
	else
		player->control = (player->control ^ MOVE_MARKER);
}

int	key_release(int key, void *param)
{
	t_engine	*engine;
	t_player	*player;

	engine = (t_engine *)param;
	player = engine->player;
	if (key == RSFT_KEY)
		player->control = (player->control ^ RSFT_CTRL) ^ SPEED_MARKER;
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		player_move_remover(key, player);
	else if (key == LEFT_KEY)
		player->control = (player->control ^ LEFT_CTRL) ^ CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		player->control = (player->control ^ RIGHT_CTRL) ^ CAMERA_MARKER;
	else if (key == U_KEY || key == J_KEY || key == I_KEY || key == K_KEY
		|| key == O_KEY || key == L_KEY)
		sprite_transformation_remover(key, player);
	else if (key == P_KEY)
		engine->bonus ^= FPS_BONUS;
	else if (key == E_KEY || key == Q_KEY)
		secret_door_remover_bonus(key, player);
	else if (key == LSFT_KEY)
		player->control = (player->control ^ LSFT_CTRL) ^ MOUSE_MARKER;
	if (player->control != NO_CTRL)
		return (true);
	return (false);
}
