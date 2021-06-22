/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:46:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:12:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*malloc_image(void *mlx_ptr, int resoluction_x, int resolution_y)
{
	t_image	*result;

	result = (t_image *)malloc(sizeof(t_image));
	if (result == NULL)
		cub3d_error(ERROR_IMAGE1, "Can't malloc t_image in constructor");
	*result = create_image(mlx_ptr, resoluction_x, resolution_y);
	return (result);
}

t_image	create_image(void *mlx_ptr, int resolution_x, int resolution_y)
{
	t_image	result;

	result.resolution = create_int_vector2(resolution_x, resolution_y);
	result.mlx_ptr = mlx_ptr;
	result.img_ptr = mlx_new_image(mlx_ptr, result.resolution.x,
			result.resolution.y);
	result.pixels = mlx_get_data_addr(result.img_ptr,
			&(result.bits_per_pixels), &(result.size_line), &(result.endian));
	return (result);
}

void	destroy_image(t_image to_destroy)
{
	mlx_destroy_image(to_destroy.mlx_ptr, to_destroy.img_ptr);
}

void	free_image(t_image *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
