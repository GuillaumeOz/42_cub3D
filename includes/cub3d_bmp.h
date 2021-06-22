/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:51:21 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 19:31:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BMP_H
# define CUB3D_BMP_H

typedef struct s_bmp_bitmap
{
	t_uint32	file_size;
	t_uint16	reserved_1;
	t_uint16	reserved_2;
	t_uint32	pixel_offset;
	t_uint32	dib_header_size;
	t_uint32	image_width;
	t_uint32	image_height;
	t_uint16	planes;
	t_uint16	bits_per_pixel;
	t_uint32	compression;
	t_uint32	image_size;
	t_uint32	x_pixels_per_meter;
	t_uint32	y_pixels_per_meter;
	t_uint32	colors_in_color_table;
	t_uint32	important_color_count;
}				t_bmp_bitmap;

t_bmp_bitmap	*malloc_bmp_bitmap(void);
t_bmp_bitmap	create_bmp_bitmap(void);
void			destroy_bmp_bitmap(t_bmp_bitmap to_destroy);
void			free_bmp_bitmap(t_bmp_bitmap *to_free);

void			quit_bmp(t_engine *engine);
void			save_bmp(t_engine *engine);

#endif