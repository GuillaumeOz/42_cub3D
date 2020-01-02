/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_application.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:48:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 13:40:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_APPLICATION_H
# define CUBE3D_APPLICATION_H

typedef struct	s_application
{
	int		size_x;
	int		size_y;
	char	*title;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	int 	bits_per_pixels;
	int 	size_line;
	int 	endian;
	char	*pixels;
}				t_application;

t_application	*malloc_application(int x, int y, char *title);
t_application	create_application(int x, int y, char *title);
void			destroy_application(t_application to_destroy);
void			free_application(t_application *to_free);
int				run_application(t_application *application);

void 			clear_application(t_application *application, t_color *background);
void 			put_pixel(t_application *application, int x, int y, t_color color);
void 			render_application(t_application *application);

#endif