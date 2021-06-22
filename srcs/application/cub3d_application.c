/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:07:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:05:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_application	*start_application(int resolution_x,
	int resolution_y, char *title)
{
	t_application	*app;

	app = (t_application *)malloc(sizeof(t_application));
	if (app == NULL)
		cub3d_error(ERROR_APPLICATION1, "The application can't be malloc");
	app->title = title;
	app->mlx_ptr = mlx_init();
	app->resolution = create_int_vector2(resolution_x, resolution_y);
	app->win_ptr = mlx_new_window(app->mlx_ptr, app->resolution.x,
			app->resolution.y, app->title);
	app->image = malloc_image(app->mlx_ptr, resolution_x, resolution_y);
	return (app);
}

void	close_application(t_application *app)
{
	free_image(app->image);
	mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	mlx_destroy_display(app->mlx_ptr);
	free(app->mlx_ptr);
	free(app);
}

void	resize_application(t_application *app,
	int resolution_x, int resolution_y)
{
	free_image(app->image);
	mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	app->resolution = create_int_vector2(resolution_x, resolution_y);
	app->win_ptr = mlx_new_window(app->mlx_ptr, app->resolution.x,
			app->resolution.y, app->title);
	app->image = malloc_image(app->mlx_ptr, resolution_x, resolution_y);
}

void	clear_application(t_application *app, t_color color)
{
	t_int_vector2	pos;

	pos = create_int_vector2(0, 0);
	mlx_do_sync(app->mlx_ptr);
	while (pos.x < app->resolution.x)
	{
		pos.y = 0;
		while (pos.y < app->resolution.y)
		{
			set_pixel_to_image(app, pos.x, pos.y, color);
			pos.y++;
		}
		pos.x++;
	}
}

int	application_run(t_application *app)
{
	mlx_loop(app->mlx_ptr);
	return (0);
}
