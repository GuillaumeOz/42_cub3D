/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:37 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:31:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_image	*malloc_image(int size_x, int size_y)
{
	t_image *result;

	result = (t_image*)malloc(sizeof(t_image));
	if (result == NULL)
		ggl_error("Error 1\n Can't malloc t_image in constructor");
	*result = create_image(size_x, size_y);
	return (result);
}

t_image	create_image(int size_x, int size_y)
{
	t_image result;

	result.size = create_vector2(size_x, size_y);
	result.img_ptr = mlx_new_image(g_app->mlx_ptr, result.size.x,
		result.size.y);
	result.pixels = mlx_get_data_addr(result.img_ptr,
									&(result.bits_per_pixels),
									&(result.size_line),
									&(result.endian));
	return (result);
}

t_image	*load_image(char *path)
{
	t_image *result;
	int		x;
	int		y;

	x = 0;
	y = 0;
	result = (t_image*)malloc(sizeof(t_image));
	if (result == NULL)
		ggl_error("Error 1\n Can't malloc t_image in load_image");
	result->img_ptr = path == NULL ? NULL :
		mlx_xpm_file_to_image(g_app->mlx_ptr, path, &x, &y);
	if (result->img_ptr == NULL)
		ggl_error("Error 2\n Error with mlx_xpm_file_to_image in load_image");
	result->size = create_vector2(x, y);
	result->pixels = mlx_get_data_addr(result->img_ptr,
									&(result->bits_per_pixels),
									&(result->size_line),
									&(result->endian));
	result->path = path;
	return (result);
}

void	destroy_image(t_image to_destroy)
{
	mlx_destroy_image(g_app->mlx_ptr, to_destroy.img_ptr);
}

void	free_image(t_image *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
