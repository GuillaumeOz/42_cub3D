/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_camera_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:11:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 22:26:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_move(t_engine *engine, t_player *player)
{
	if (player->control & MOUSE_MARKER && BONUS == true)
		mlx_hook(engine->app->win_ptr, MOTIONNOTIFY,
			POINTERMOTIONMASK, camera_mouse_move_bonus, (void*)engine);
	else
		camera_keyboard_move(player);
}
