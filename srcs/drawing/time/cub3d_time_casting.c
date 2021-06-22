/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_time_casting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:33:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 18:15:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	time_render(t_engine *engine, t_player *player)
{
	double	frame_time;
	double	frame;
	char	*fps;

	set_old_time(player->time);
	set_current_time(player->time);
	frame_time = (get_time(player->time) - get_old_time(player->time)) / 1000.0;
	player->move_speed = frame_time * 3.0;
	player->rot_speed = frame_time * 2.0;
	if (engine->bonus & FPS_BONUS && BONUS == true)
	{
		frame = 1.0 / frame_time;
		fps = ft_itoa(frame);
		mlx_string_put(engine->app->mlx_ptr, engine->app->win_ptr,
			(engine->resolution.x - 20), 20, 0x00FFFF, fps);
		free(fps);
	}
}
