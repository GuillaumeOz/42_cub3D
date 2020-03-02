/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:23:10 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/25 19:45:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void application_create_content()
{
	g_app->image = malloc_image(g_app->size.x, g_app->size.y);
}

void render_application()
{
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->image->img_ptr, 0, 0);
}

void add_interaction_to_application(int event, t_key_funct funct, void *param)
{
	mlx_hook(g_app->win_ptr, event, 0, funct, param);
}

void render_funct_application(t_render_funct funct, void *param)
{
	mlx_loop_hook(g_app->mlx_ptr, funct, param);
}
