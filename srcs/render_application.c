/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:06:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 10:08:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define RED_VALUE 2
#define GREEN_VALUE 1
#define BLUE_VALUE 0

void	clear_application(t_application *application, t_color *background)
{
	int	nb_pixel;
	int	pixel_index;
	int rel_pixel_index;

	nb_pixel = application->size_x * application->size_y;
	pixel_index = 0;
	while (pixel_index < nb_pixel)
	{
		rel_pixel_index = pixel_index * 4;
		
		application->pixels[rel_pixel_index + RED_VALUE] = background->r;
		application->pixels[rel_pixel_index + GREEN_VALUE] = background->g;
		application->pixels[rel_pixel_index + BLUE_VALUE] = background->b;

		pixel_index++;
	}
}

void	put_pixel(t_application *application, int x , int y, t_color color)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= application->size_x || y < 0 || y >= application->size_y)
		return ;
		
	pixel_index = x + (y * application->size_x);
	
	rel_pixel_index = pixel_index * 4;
	
	application->pixels[rel_pixel_index + RED_VALUE] = color.r;
	application->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	application->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}

void	render_application(t_application *application)
{
	mlx_put_image_to_window(application->mlx_ptr,
			application->win_ptr,
			application->img_ptr,
			0, 0);
}

int				run_application(t_application *t_application)
{
	mlx_loop(t_application->mlx_ptr);
	return (0);
}
