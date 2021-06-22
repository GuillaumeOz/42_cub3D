/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:37:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/22 13:09:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	routine(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	mlx_do_sync(engine->app->mlx_ptr);
	event_manager(engine);
	floor_ceiling_render(engine, engine->player);
	wall_render(engine, engine->player);
	sprite_render_bonus(engine, engine->player);
	minimap_render_bonus(engine, engine->player);
	secret_door_render_bonus(engine, engine->player);
	player_move(engine->player, engine->map);
	camera_move(engine, engine->player);
	application_render(engine->app);
	time_render(engine, engine->player);
	mlx_loop(engine->app->mlx_ptr);
	return (0);
}
