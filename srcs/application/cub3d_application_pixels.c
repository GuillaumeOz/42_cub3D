/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_application_pixels.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:35:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 16:35:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pixel_to_image(t_application *app, int x, int y, t_color color)
{
	char	*temp;

	if (x < 0 || x >= app->resolution.x
		|| y < 0 || y >= app->resolution.y)
		return ;
	temp = app->image->pixels + (y * app->image->size_line
			+ x * (app->image->bits_per_pixels / 8));
	temp[RED_COMP] = color.r;
	temp[GREEN_COMP] = color.g;
	temp[BLUE_COMP] = color.b;
	temp[ALPHA_COMP] = color.a;
}

void	clear_screen(t_application *app)
{
	int	i;
	int	j;

	mlx_clear_window(app->mlx_ptr, app->win_ptr);
	i = 0;
	while (i < app->resolution.x)
	{
		j = 0;
		while (j < app->resolution.y)
		{
			set_pixel_to_image(app, i, j, create_color(0, 0, 0, 255));
			j++;
		}
		i++;
	}
}
