/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:24:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:13:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*malloc_player(double pos_x, double pos_y, t_player_dir dir)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		cub3d_error(ERROR_PLAYER1, "t_player can't be malloc");
	*player = create_player(pos_x, pos_y, dir);
	return (player);
}

static void	set_player_direction(t_player *player, t_player_dir direction)
{
	t_double_vector2	plane;
	t_double_vector2	dir;

	if (direction == NORTH_DIR)
	{
		dir = create_double_vector2(0.0, -1.0);
		plane = create_double_vector2(-0.66, 0.0);
	}
	else if (direction == SOUTH_DIR)
	{
		dir = create_double_vector2(0.0, 1.0);
		plane = create_double_vector2(0.66, 0.0);
	}
	else if (direction == EAST_DIR)
	{
		dir = create_double_vector2(1.0, 0.0);
		plane = create_double_vector2(0.0, -0.66);
	}
	else if (direction == WEST_DIR)
	{
		dir = create_double_vector2(-1.0, 0.0);
		plane = create_double_vector2(0.0, 0.66);
	}
	player->plane = plane;
	player->dir = dir;
}

t_player	create_player(double pos_x, double pos_y, t_player_dir dir)
{
	t_player	player;

	player.pos = create_double_vector2(pos_x, pos_y);
	set_player_direction(&player, dir);
	player.old_dir = create_double_vector2(0.0, 0.0);
	player.old_plane = create_double_vector2(0.0, 0.0);
	player.mouse_pos = 0;
	player.move_speed = 0;
	player.rot_speed = 0.0f;
	player.time = malloc_time();
	player.control = NO_CTRL;
	return (player);
}

void	destroy_player(t_player to_destroy)
{
	free_time(to_destroy.time);
}

void	free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}
