/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:40:27 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:23:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*malloc_sprite(t_application *app,
		char *path, t_sprite_id sprite_id)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		cub3d_error(ERROR_SPRITE1, "t_sprite* can't be malloc");
	*sprite = create_sprite(app, path, sprite_id);
	return (sprite);
}

t_sprite	create_sprite(t_application *app,
		char *path, t_sprite_id sprite_id)
{
	t_sprite		sprite;
	t_int_vector2	tex;

	sprite.app = app;
	sprite.path = ft_strdup(path);
	sprite.sprite_id = sprite_id;
	tex = create_int_vector2(0, 0);
	sprite.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, path, &tex.x, &tex.y);
	if (sprite.img_ptr == NULL)
		cub3d_error(ERROR_SPRITE2,
			"mlx_xpm_file_to_image failed in create_sprite");
	sprite.tex_resolution = create_int_vector2(tex.x, tex.y);
	sprite.pixels = (int *)mlx_get_data_addr(sprite.img_ptr,
			&(sprite.bits_per_pixels), &(sprite.size_line), &(sprite.endian));
	return (sprite);
}

void	destroy_sprite(t_sprite to_destroy)
{
	free(to_destroy.path);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr);
}

void	free_sprite(t_sprite *to_free)
{
	destroy_sprite(*to_free);
	free(to_free);
}
