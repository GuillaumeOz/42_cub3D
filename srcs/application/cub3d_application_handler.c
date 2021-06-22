/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_application_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:23:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 16:05:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	application_exit_control(t_exit_funct funct, int event,
	int maskevent, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	mlx_hook(engine->app->win_ptr, event, maskevent, funct, param);
}

void	application_control(t_key_funct funct, int event,
	int maskevent, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	mlx_hook(engine->app->win_ptr, event, maskevent, funct, param);
}

void	application_routine(t_routine_funct funct, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	mlx_loop_hook(engine->app->mlx_ptr, funct, param);
}

void	application_render(t_application *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr,
		app->image->img_ptr, 0, 0);
}
