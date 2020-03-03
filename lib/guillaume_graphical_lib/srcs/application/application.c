/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 12:07:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/28 13:58:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	start_application(int size_x, int size_y, char *title)
{
	g_app = (t_application*)malloc(sizeof(t_application));
	if (g_app == NULL)
		ggl_error("Error\n The application can't be malloc");
	g_app->title = title;
	g_app->mlx_ptr = mlx_init();
	g_app->size = create_vector2(size_x, size_y);
	g_app->win_ptr = mlx_new_window(g_app->mlx_ptr, g_app->size.x, g_app->size.y, g_app->title);
	g_app->image = NULL;
}

void	close_application()
{
	free_image(g_app->image);
	mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);
	free(g_app);
	ggl_putstr("The application has been closed");
	exit(0);
}

void	resize_application(int size_x, int size_y)
{
	if (g_app->image != NULL)
		free_image(g_app->image);
	mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);
	g_app->size = create_vector2(size_x, size_y);
	g_app->win_ptr = mlx_new_window(g_app->mlx_ptr, g_app->size.x, g_app->size.y, g_app->title);
	g_app->image = malloc_image(g_app->size.x, g_app->size.y);
}

void	clear_application(t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < (size_t)g_app->size.x)
	{
		j = 0;
		while (j < (size_t)g_app->size.y)
		{
			put_pixel(g_app->image, i, j, color);
			j++;
		}
		i++;
	}
}

int		run_application()
{
	mlx_loop(g_app->mlx_ptr);
	return (0);
}
