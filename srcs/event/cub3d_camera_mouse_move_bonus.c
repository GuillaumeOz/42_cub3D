/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_camera_mouse_move_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:50:57 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 22:27:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	camera_mouse_move_left_bonus(t_player *player)
{
	double	mouse_rot_speed;

	mouse_rot_speed = player->rot_speed / 5;
	if (player->control & LSFT_CTRL)
	{
		player->old_dir.x = player->dir.x;
		player->dir.x = player->dir.x * cos(-mouse_rot_speed)
			- player->dir.y * sin(-mouse_rot_speed);
		player->dir.y = player->old_dir.x * sin(-mouse_rot_speed)
			+ player->dir.y * cos(-mouse_rot_speed);
		player->old_plane.x = player->plane.x;
		player->plane.x = player->plane.x * cos(-mouse_rot_speed)
			- player->plane.y * sin(-mouse_rot_speed);
		player->plane.y = player->old_plane.x * sin(-mouse_rot_speed)
			+ player->plane.y * cos(-mouse_rot_speed);
	}
}

static void	camera_mouse_move_right_bonus(t_player *player)
{
	double	mouse_rot_speed;

	mouse_rot_speed = player->rot_speed / 5;
	if (player->control & LSFT_CTRL)
	{
		player->old_dir.x = player->dir.x;
		player->dir.x = player->dir.x * cos(mouse_rot_speed)
			- player->dir.y * sin(mouse_rot_speed);
		player->dir.y = player->old_dir.x * sin(mouse_rot_speed)
			+ player->dir.y * cos(mouse_rot_speed);
		player->old_plane.x = player->plane.x;
		player->plane.x = player->plane.x * cos(mouse_rot_speed)
			- player->plane.y * sin(mouse_rot_speed);
		player->plane.y = player->old_plane.x * sin(mouse_rot_speed)
			+ player->plane.y * cos(mouse_rot_speed);
	}
}

int	camera_mouse_move_bonus(int x, int y, void *param)
{
	t_engine	*engine;
	t_player	*player;

	(void)y;
	engine = (t_engine *)param;
	player = engine->player;
	if (player->mouse_pos == 0)
	{
		player->mouse_pos = x;
		return (false);
	}
	if (x < player->mouse_pos)
		camera_mouse_move_left_bonus(player);
	else if (x > player->mouse_pos)
		camera_mouse_move_right_bonus(player);
	player->mouse_pos = x;
	return (true);
}
