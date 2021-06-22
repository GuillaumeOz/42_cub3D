/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_secret_door_render_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:24:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 21:31:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	set_secret_door_wall_calc(t_wall_calc *secret_door,
	t_player *player)
{
	secret_door->map = NULL;
	secret_door->camera_x = 0.0f;
	secret_door->map_pos = create_int_vector2((int)player->pos.x,
			(int)player->pos.y);
	secret_door->ray_dir = create_double_vector2(player->dir.x, player->dir.y);
	secret_door->delta_dist = create_double_vector2(sqrt(1
				+ (secret_door->ray_dir.y * secret_door->ray_dir.y)
				/ (secret_door->ray_dir.x * secret_door->ray_dir.x)),
			sqrt(1 + (secret_door->ray_dir.x * secret_door->ray_dir.x)
				/ (secret_door->ray_dir.y * secret_door->ray_dir.y)));
}

static	void	set_secret_door_step_side_dist(t_wall_calc *secret_door,
	t_player *player)
{
	if (secret_door->ray_dir.x <= 0)
	{
		secret_door->step.x = -1;
		secret_door->side_dist.x = (player->pos.x - secret_door->map_pos.x)
			* secret_door->delta_dist.x;
	}
	else
	{
		secret_door->step.x = 1;
		secret_door->side_dist.x = (secret_door->map_pos.x + 1.0
				- player->pos.x) * secret_door->delta_dist.x;
	}
	if (secret_door->ray_dir.y <= 0)
	{
		secret_door->step.y = -1;
		secret_door->side_dist.y = (player->pos.y - secret_door->map_pos.y)
			* secret_door->delta_dist.y;
	}
	else
	{
		secret_door->step.y = 1;
		secret_door->side_dist.y = (secret_door->map_pos.y + 1.0
				- player->pos.y) * secret_door->delta_dist.y;
	}
}

static	void	secret_door_action_catcher(t_engine *engine, t_player *player)
{
	t_wall_calc			secret_door;

	set_secret_door_wall_calc(&secret_door, player);
	set_secret_door_step_side_dist(&secret_door, player);
	if (player->control & E_CTRL)
	{
		if (find_diamond_block_bonus(&secret_door, engine) == true)
		{
			secret_door.map = list_at(engine->map, secret_door.map_pos.y);
			if (secret_door.map[secret_door.map_pos.x] != 'k')
				secret_door.map[secret_door.map_pos.x] += 1;
			else if (secret_door.map[secret_door.map_pos.x] == 'k')
				secret_door.map[secret_door.map_pos.x] = '0';
		}
	}
	else if (player->control & Q_CTRL)
	{
		if (put_diamond_block_bonus(&secret_door, engine) == true)
		{
			secret_door.map = list_at(engine->map, secret_door.map_pos.y);
			if (secret_door.map[secret_door.map_pos.x] == '0')
				secret_door.map[secret_door.map_pos.x] = 'a';
		}
	}
}

void	secret_door_render_bonus(t_engine *engine, t_player *player)
{
	if (player->control & ACTION_MARKER && BONUS == true)
		secret_door_action_catcher(engine, player);
}
