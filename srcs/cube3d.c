/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:54:50 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/04 19:39:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
	t_config		*config;
	t_application	*application;

	if (argc != 2)
		catch_error(MAIN_1);
	config = cube_formatter("Cube3D", argv[1]);

	application = malloc_application(config->resolution_size->x,
		config->resolution_size->y, config->title);
	//clear_application(config, application);
	render_application(config, application);
	run_application(application);

	// free_application(application);
	// free_config(config);
	//draw_ground()
	//put the event there
	//mlx_hook(application->win_ptr, ESC_KEY, int x_mask,
    //             int (*funct)(), void *param);
	//application is running there
	//render_application(application);

	return (0);
}

// #include <mlx.h>

// typedef struct	s_application
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*img_ptr;

// 	int 	bits_per_pixels;
// 	int 	size_line;
// 	int 	endian;
// 	char	*pixels;
// }				t_application;

// void            my_mlx_pixel_put(t_application *applicaton, int x, int y, int color)
// {
//     char    *dst;

//     dst = applicaton->pixels + (y * applicaton->size_line + x * (applicaton->bits_per_pixels / 8));
//     *(unsigned int*)dst = color;
// }

// int             main(void)
// {
//     t_application  application;

//     application.mlx_ptr = mlx_init();
//     application.win_ptr = mlx_new_window(application.mlx_ptr, 1920, 1080, "Hello world!");
//     application.img_ptr = mlx_new_image(application.mlx_ptr, 1920, 1080);
//     application.pixels = mlx_get_data_addr(application.img_ptr, &application.bits_per_pixels, &application.size_line,
//                                  &application.endian);
//     my_mlx_pixel_put(&application, 5, 5, 0x00ffff00);
//     mlx_put_image_to_window(application.mlx_ptr, application.win_ptr, application.img_ptr, 0, 0);
//     mlx_loop(application.mlx_ptr);
// }
