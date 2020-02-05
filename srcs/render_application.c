/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:06:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/05 16:12:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int             event_gen(int keycode, t_application *application)
{
	application->bits_per_pixels = 0;
	if (keycode == ESC_KEY)
		exit(0);
    	//mlx_destroy_window(application->mlx_ptr, application->win_ptr);
	return (53);
}

void	render_application(t_config *config, t_application *application)
{
	clear_application(config, application);
	cube_print_map(config, application);
	mlx_put_image_to_window(application->mlx_ptr,
			application->win_ptr,
			application->img_ptr,
			0, 0);
}

int				run_application(t_application *application)
{
	mlx_key_hook(application->win_ptr, event_gen, application);// create a global function, check with bitshift ?
	mlx_loop(application->mlx_ptr);
	return (0);
}
