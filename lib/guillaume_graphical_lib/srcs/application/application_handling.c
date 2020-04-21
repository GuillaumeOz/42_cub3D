/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:23:10 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/21 19:11:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	application_create_content()
{
	g_app->image = malloc_image(g_app->size.x, g_app->size.y);
}

void	application_add_exit_control(int event, int (*funct)(void))
{
	mlx_hook(g_app->win_ptr, event, 0L, funct, (void*)0);
}

void	render_application()
{
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->image->img_ptr, 0, 0);
}

void add_interaction_to_application(t_key_funct funct, int event, int maskevent, void *param)
{
	mlx_hook(g_app->win_ptr, event, maskevent, funct, param);
}

void render_funct_application(t_render_funct funct, void *param)
{
	mlx_loop_hook(g_app->mlx_ptr, funct, param);
}
