/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:31:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 16:49:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_image	create_image_from_file(char *path)
{
	t_image result;
	int		x;
	int		y;

	x = 0;
	y = 0;
	result.bits_per_pixels = 0;
	result.size_line = 0;
	result.endian = 0;
	result.img_ptr = mlx_xpm_file_to_image(g_app->mlx_ptr, path,
										&(x), &(y));
	result.size = create_vector2(x, y);
	result.pixels = mlx_get_data_addr(result.img_ptr, &(result.bits_per_pixels),
										&(result.size_line), &(result.endian));
	return (result);
}

t_image	*malloc_image_from_file(char *path)
{
	t_image *result;

	result = (t_image *)malloc(sizeof(t_image));
	if (result == NULL)
		ggl_error("Error\n Malloc image from file failed");
	*result = create_image_from_file(path);
	return (result);
}
