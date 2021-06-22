/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_texture.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:37:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 18:06:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_TEXTURE_H
# define CUB3D_T_TEXTURE_H

typedef enum e_texture_id
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR_BONUS,
	CEILING_BONUS,
	SECRET_DOOR_BONUS,
	NONE,
}					t_texture_id;

typedef struct s_texture
{
	t_application	*app;
	char			*path;
	t_texture_id	texture_id;
	t_int_vector2	tex_resolution;
	void			*img_ptr;
	int				*pixels;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}					t_texture;

t_texture		*malloc_texture(t_application *app,
					char *path, t_texture_id texture_id);
t_texture		create_texture(t_application *app,
					char *path, t_texture_id texture_id);
void			destroy_texture(t_texture to_destroy);
void			free_texture(t_texture *to_free);

#endif