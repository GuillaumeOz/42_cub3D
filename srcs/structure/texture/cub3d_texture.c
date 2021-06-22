/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:49:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:35:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*malloc_texture(t_application *app,
	char *path, t_texture_id texture_id)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		cub3d_error(ERROR_TEXTURE1, "t_texture* can't be malloc");
	*texture = create_texture(app, path, texture_id);
	return (texture);
}

t_texture	create_texture(t_application *app,
	char *path, t_texture_id texture_id)
{
	t_texture		texture;
	t_int_vector2	tex;

	texture.app = app;
	texture.path = ft_strdup(path);
	texture.texture_id = texture_id;
	tex = create_int_vector2(0, 0);
	texture.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, path, &tex.x, &tex.y);
	if (texture.img_ptr == NULL)
		cub3d_error(ERROR_TEXTURE2,
			"mlx_xpm_file_to_image failed in create_texture");
	texture.tex_resolution = create_int_vector2(tex.x, tex.y);
	texture.pixels = (int *)mlx_get_data_addr(texture.img_ptr,
			&(texture.bits_per_pixels), &(texture.size_line),
			&(texture.endian));
	return (texture);
}

void	destroy_texture(t_texture to_destroy)
{
	free(to_destroy.path);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr);
}

void	free_texture(t_texture *to_free)
{
	destroy_texture(*to_free);
	free(to_free);
}
