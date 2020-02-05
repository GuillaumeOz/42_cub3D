/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:55:11 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/05 19:59:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		put_pixel(t_config *config, t_application *application, 
	t_vector pos, t_color color)
{
	int pixel_index;
	int rel_pixel_index;

	if (pos.x < 0 || pos.x >= config->resolution_size->x || pos.y < 0 ||
		pos.y >= config->resolution_size->y)
		return ;
	pixel_index = pos.x + (pos.y * config->resolution_size->x);
	rel_pixel_index = pixel_index * 4;
	application->pixels[rel_pixel_index + BLUE_COMP] = color.b;
	application->pixels[rel_pixel_index + GREEN_COMP] = color.g;
	application->pixels[rel_pixel_index + RED_COMP] = color.r;
	application->pixels[rel_pixel_index + ALPHA_COMP] = color.t;
}

void		clear_application(t_config *config, t_application *application)
{
	t_color color;
	int	nb_pixel;
	int	pixel_index;
	int rel_pixel_index;

	color = create_color(255, 255, 255, 0);
	nb_pixel = config->resolution_size->x * config->resolution_size->y;
	pixel_index = 0;
	while (pixel_index < nb_pixel)
	{
		rel_pixel_index = pixel_index * 4;
		application->pixels[rel_pixel_index + BLUE_COMP] = color.b;
		application->pixels[rel_pixel_index + GREEN_COMP] = color.g;
		application->pixels[rel_pixel_index + RED_COMP] = color.r;
		application->pixels[rel_pixel_index + ALPHA_COMP] = color.t;
		pixel_index++;
	}
}

void	draw_rectangle(t_config *config, t_application *application, t_vector square_pos)
{
	t_color		rectangle_color;
	t_vector	pos;
	t_vector	rounded;
	int i;
	int j;

	i = -1;
	j = -1;
	rectangle_color = create_color(0, 0, 0, 0);
	pos = create_vector(0.0, 0.0);
	if (config->proportionality->y + 0.5f == ((int)config->proportionality->y + 1))
		rounded.y = roundf(config->proportionality->y + 0.5f);
	else
		rounded.y = roundf(config->proportionality->y);
	if (config->proportionality->x + 0.5f == ((int)config->proportionality->x + 1))
		rounded.x = roundf(config->proportionality->x + 0.5f);
	else
		rounded.x = roundf(config->proportionality->x);
	// config->proportionality->y = roundf(config->proportionality->y);
	// config->proportionality->x = roundf(config->proportionality->x);
	PRINTF(rounded.y);
	PRINTF(rounded.x);
	while (++i <= (rounded.y + 20))
	{
		pos.y = i + square_pos.y;
		while (++j <= (rounded.x + 20))
		{
			pos.x = j + square_pos.x;
			put_pixel(config, application, pos, rectangle_color);
		}
		j = -1;
	}
}
