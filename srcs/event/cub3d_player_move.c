/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:11:27 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 20:29:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_up(t_player *player, t_list *map_list)
{
	double	x;
	double	y;

	x = player->pos.x + player->dir.x * player->move_speed;
	y = player->pos.y + player->dir.y * player->move_speed;
	if (hitbox(x, y, map_list) == false)
	{
		player->pos.x = x;
		player->pos.y = y;
	}
}

static void	move_down(t_player *player, t_list *map_list)
{
	double	x;
	double	y;

	x = player->pos.x - player->dir.x * player->move_speed;
	y = player->pos.y - player->dir.y * player->move_speed;
	if (hitbox(x, y, map_list) == false)
	{
		player->pos.x = x;
		player->pos.y = y;
	}
}

static void	move_right(t_player *player, t_list *map_list)
{
	double	x;
	double	y;

	x = player->pos.x - player->plane.x * player->move_speed;
	y = player->pos.y - player->plane.y * player->move_speed;
	if (hitbox(x, y, map_list) == false)
	{
		player->pos.x = x;
		player->pos.y = y;
	}
}

static void	move_left(t_player *player, t_list *map_list)
{
	double	x;
	double	y;

	x = player->pos.x + player->plane.x * player->move_speed;
	y = player->pos.y + player->plane.y * player->move_speed;
	if (hitbox(x, y, map_list) == false)
	{
		player->pos.x = x;
		player->pos.y = y;
	}
}

void	player_move(t_player *player, t_list *map_list)
{
	if (player->control & RSFT_CTRL || player->control & SPEED_MARKER)
		player->move_speed *= 1.5;
	if (player->control & MOVE_MARKER)
	{
		if (player->control & W_CTRL)
			move_up(player, map_list);
		if (player->control & S_CTRL)
			move_down(player, map_list);
		if (player->control & A_CTRL)
			move_left(player, map_list);
		if (player->control & D_CTRL)
			move_right(player, map_list);
	}
}
