/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:23:10 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 14:46:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	add_interaction_exit_control(t_exit_funct funct, int event,
	int maskevent, void *param)
{
	mlx_hook(g_app->win_ptr, event, maskevent, funct, param);
}

void	add_interaction_to_application(t_key_funct funct, int event,
	int maskevent, void *param)
{
	mlx_hook(g_app->win_ptr, event, maskevent, funct, param);
}

void	application_update(t_render_funct funct, void *param)
{
	mlx_loop_hook(g_app->mlx_ptr, funct, param);
}

void	render_application(void)
{
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr,
		g_app->image->img_ptr, 0, 0);
}
