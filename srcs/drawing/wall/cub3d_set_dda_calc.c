/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_dda_calc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:06:15 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 21:29:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	y_axis_wall_texture_selector(t_wall_calc *wall_calc)
{
	if (wall_calc->ray_dir.y < 0)
		wall_calc->id = SOUTH;
	else
		wall_calc->id = NORTH;
}

static void	x_axis_wall_texture_selector(t_wall_calc *wall_calc)
{
	if (wall_calc->ray_dir.x < 0)
		wall_calc->id = EAST;
	else
		wall_calc->id = WEST;
}

static bool	analyse_map_tile(t_wall_calc *wall_calc, int pos_x)
{
	if (wall_calc->map[pos_x] == '1')
	{
		wall_calc->hit_char = '1';
		return (true);
	}
	else if (ft_ischar("abcdefghijk", wall_calc->map[pos_x]) == true)
	{
		wall_calc->hit_char = wall_calc->map[pos_x];
		return (true);
	}
	return (false);
}

static bool	set_dda_map_limit(t_wall_calc *wall_calc, t_engine *engine)
{
	if (wall_calc->map_pos.x < 0 || wall_calc->map_pos.y < 0
		|| wall_calc->map_pos.y > ((int)engine->map->size - 1)
		|| wall_calc->map_pos.x > ((int)(ft_strlen(wall_calc->map) - 1)))
		return (true);
	return (false);
}

bool	set_dda_calc(t_wall_calc *wall_calc, t_engine *engine)
{
	wall_calc->hit = false;
	while (wall_calc->hit == false)
	{
		if (wall_calc->side_dist.x < wall_calc->side_dist.y)
		{
			wall_calc->side_dist.x += wall_calc->delta_dist.x;
			wall_calc->map_pos.x += wall_calc->step.x;
			x_axis_wall_texture_selector(wall_calc);
		}
		else
		{
			wall_calc->side_dist.y += wall_calc->delta_dist.y;
			wall_calc->map_pos.y += wall_calc->step.y;
			y_axis_wall_texture_selector(wall_calc);
		}
		wall_calc->map = list_at(engine->map, wall_calc->map_pos.y);
		if (set_dda_map_limit(wall_calc, engine) == true)
			return (false);
		if (analyse_map_tile(wall_calc, wall_calc->map_pos.x) == true)
		{
			wall_calc->hit = true;
			return (true);
		}
	}
	return (true);
}
