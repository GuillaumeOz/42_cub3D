/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:11:21 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 17:09:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_IMAGE_H
# define GGL_IMAGE_H

typedef struct	s_image
{
	t_vector2	size;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixels;
	int			size_line;
	int			endian;
	char		*path;
}				t_image;

t_image			*malloc_image(int size_x, int size_y);
t_image			create_image(int size_x, int size_y);
void			destroy_image(t_image to_destroy);
void			free_image(t_image *to_free);
t_image			*load_image(char *path);

t_image			*malloc_image_from_file(char *path);
t_image			create_image_from_file(char *path);
void			destroy_image_from_file(t_image image);
void			free_image_from_file(t_image *image);

#endif
