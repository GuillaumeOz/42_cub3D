/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:11:21 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/25 14:12:01 by gozsertt         ###   ########.fr       */
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
}				t_image;

t_image			*malloc_image(int size_x, int size_y);
t_image			create_image(int size_x, int size_y);
void			destroy_image(t_image to_destroy);
void			free_image(t_image *to_free);

t_image			*load_image(char *path);

#endif