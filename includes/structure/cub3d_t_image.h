/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_image.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:41:35 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/07 16:13:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_IMAGE_H
# define CUB3D_T_IMAGE_H

typedef struct s_image
{
	t_int_vector2	resolution;
	void			*mlx_ptr;
	void			*img_ptr;
	char			*pixels;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}				t_image;

//t_image
t_image			*malloc_image(void *mlx_ptr, int resoluction_x,
					int resolution_y);
t_image			create_image(void *mlx_ptr, int resoluction_x,
					int resolution_y);
void			destroy_image(t_image to_destroy);
void			free_image(t_image *to_free);

#endif
