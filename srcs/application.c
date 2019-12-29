/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 12:07:29 by gozsertt          #+#    #+#             */
/*   Updated: 2019/12/29 20:20:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_application	create_application(int x, int y, char *title)
{
	t_application result;

	result.size_x = x;
	result.size_y = y;
	result.title = title;

	result.mlx_ptr = mlx_init(); // protect the return value $ env -i <votre-executable>
	result.win_ptr = mlx_new_window(result.mlx_ptr, result.size_x, result.size_y, result.title); // Same
	result.img_ptr = mlx_new_image(result.mlx_ptr, result.size_x, result.size_y); //Same
	return (result);
}

t_application	*malloc_application(int x, int y, char *title)
{
	t_application *application;

	if((!(application = (t_application*)malloc(sizeof(t_application)))))
		return (NULL);
	*application = create_application(x, y, title);
	return (application);
}

void			destroy_application(t_application to_destroy)
{
	mlx_destroy_image(to_destroy.mlx_ptr, to_destroy.img_ptr);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
}

void			free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}

int				run_application(t_application *t_application)
{
	mlx_loop(t_application->mlx_ptr);
	return (0);
}
