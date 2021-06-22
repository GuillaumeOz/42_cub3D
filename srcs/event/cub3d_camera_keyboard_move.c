/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_camera_keyboard_move.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:55:32 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/22 14:29:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	camera_move_left(t_player *player)
{
	player->old_dir.x = player->dir.x;
	player->dir.x = player->dir.x * cos(-player->rot_speed)
		- player->dir.y * sin(-player->rot_speed);
	player->dir.y = player->old_dir.x * sin(-player->rot_speed)
		+ player->dir.y * cos(-player->rot_speed);
	player->old_plane.x = player->plane.x;
	player->plane.x = player->plane.x * cos(-player->rot_speed)
		- player->plane.y * sin(-player->rot_speed);
	player->plane.y = player->old_plane.x * sin(-player->rot_speed)
		+ player->plane.y * cos(-player->rot_speed);
}

static void	camera_move_right(t_player *player)
{
	player->old_dir.x = player->dir.x;
	player->dir.x = player->dir.x * cos(player->rot_speed)
		- player->dir.y * sin(player->rot_speed);
	player->dir.y = player->old_dir.x * sin(player->rot_speed)
		+ player->dir.y * cos(player->rot_speed);
	player->old_plane.x = player->plane.x;
	player->plane.x = player->plane.x * cos(player->rot_speed)
		- player->plane.y * sin(player->rot_speed);
	player->plane.y = player->old_plane.x * sin(player->rot_speed)
		+ player->plane.y * cos(player->rot_speed);
}

void	camera_keyboard_move(t_player *player)
{
	if (player->control & RIGHT_CTRL)
		camera_move_right(player);
	if (player->control & LEFT_CTRL)
		camera_move_left(player);
}
