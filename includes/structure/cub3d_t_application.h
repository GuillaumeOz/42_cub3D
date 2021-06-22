/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_application.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:29:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/07 12:48:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_APPLICATION_H
# define CUB3D_T_APPLICATION_H

typedef struct s_application
{
	char			*title;
	t_int_vector2	resolution;
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*image;
}				t_application;

typedef int		(*t_exit_funct)(void *param);
typedef int		(*t_key_funct)(int key, void *param);
typedef int		(*t_routine_funct)(void *param);

t_application	*start_application(int size_x, int size_y, char *title);
void			close_application(t_application	*app);

void			set_pixel_to_image(t_application *app, int x, int y,
					t_color color);
void			clear_screen(t_application *app);
void			clear_application(t_application *app, t_color color);
void			resize_application(t_application *app, int size_x, int size_y);
int				application_run(t_application *app);

void			application_control(t_key_funct funct, int event,
					int maskevent, void *param);
void			application_exit_control(t_exit_funct funct, int event,
					int maskevent, void *param);
void			application_routine(t_routine_funct funct, void *param);
void			application_render(t_application *app);

#endif