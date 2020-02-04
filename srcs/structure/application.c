/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 12:07:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/04 13:02:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_application	create_application(int x, int y, char *title)
{
	t_application result;

	result.mlx_ptr = mlx_init(); // protect the return value $ env -i <votre-executable>
	result.win_ptr = mlx_new_window(result.mlx_ptr, x, y, title); // Same
	result.img_ptr = mlx_new_image(result.mlx_ptr, x, y); //Same
	result.pixels = mlx_get_data_addr(result.img_ptr, &(result.bits_per_pixels),
				   &(result.size_line), &(result.endian));
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
