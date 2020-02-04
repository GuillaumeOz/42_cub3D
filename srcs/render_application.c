/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:06:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/04 20:17:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define BLUE_VALUE 0
#define GREEN_VALUE 1
#define RED_VALUE 2
#define TRANSPARENCY_VALUE 3

void	clear_application(t_config *config, t_application *application)
{
	int	nb_pixel;
	int	pixel_index;
	int rel_pixel_index;

	nb_pixel = config->resolution_size->x * config->resolution_size->y;
	pixel_index = 0;
	while (pixel_index < nb_pixel)
	{
		rel_pixel_index = pixel_index * 4;
		application->pixels[rel_pixel_index + BLUE_VALUE] = config->floor->b;
		application->pixels[rel_pixel_index + GREEN_VALUE] = config->floor->g;
		application->pixels[rel_pixel_index + RED_VALUE] = config->floor->r;
		application->pixels[rel_pixel_index + TRANSPARENCY_VALUE] = config->floor->t;
		pixel_index++;
	}
}

void	put_pixel(t_config *config, t_application *application, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= config->resolution_size->x || y < 0 ||
		y >= config->resolution_size->y)
		return ;
	pixel_index = (x + 10) + ((y + 10) * config->resolution_size->x);
	rel_pixel_index = pixel_index * 4;

	application->pixels[rel_pixel_index + BLUE_VALUE] = (unsigned char)255;
	application->pixels[rel_pixel_index + GREEN_VALUE] = (unsigned char)255;
	application->pixels[rel_pixel_index + RED_VALUE] = (unsigned char)255;
	application->pixels[rel_pixel_index + TRANSPARENCY_VALUE] = (unsigned char)0;
}

void	render_application(t_config *config, t_application *application)
{
	config->floor->t = 0;
	int i;
	int j;

	i = 0;
	j = 0;
	while (config->map[i] != NULL)
	{
		while (config->map[i][j])
		{
			put_pixel(config, application, 100 + j, 100 + i);
			j++;
		}
		j = 0;
		i++;
	}
	
	// while (config->map[i] != NULL)
	// {
	// 	while (config->map[i][j])
	// 	{
	// 		if (config->map[i][j] == '1')
	// 		{
	// 			put_pixel(config, application, 100 + j, 100 + i);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// 	debug;
	// }
	mlx_put_image_to_window(application->mlx_ptr,
			application->win_ptr,
			application->img_ptr,
			0, 0);
}

int				run_application(t_application *application)
{
	mlx_loop(application->mlx_ptr);
	return (0);
}
