/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_behavior.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:35:11 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:25:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void			set_pixel(t_vector2 pos, t_color color)
{
	int pixel_index;

	if (pos.x < 0 || pos.x >= g_app->size.x || pos.y < 0 ||
												pos.y >= g_app->size.y)
		return ;
	pixel_index = convert_2di_1di(pos, g_app->size) * 4;
	g_app->image->pixels[pixel_index + RED_COMP] = color.r;
	g_app->image->pixels[pixel_index + GREEN_COMP] = color.g;
	g_app->image->pixels[pixel_index + BLUE_COMP] = color.b;
}

void			clear_screen(void)
{
	size_t i;
	size_t j;

	mlx_clear_window(g_app->mlx_ptr, g_app->win_ptr);
	i = 0;
	while (i < g_app->size.x)
	{
		j = 0;
		while (j < g_app->size.y)
		{
			set_pixel(create_vector2(i, j), create_color(0, 0, 0, 255));
			j++;
		}
		i++;
	}
}
