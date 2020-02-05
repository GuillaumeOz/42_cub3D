/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_application.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:48:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/05 16:20:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_APPLICATION_H
# define CUBE3D_APPLICATION_H

typedef struct	s_application
{
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

void 			clear_application(t_config *config, t_application *application);
void			draw_rectangle(t_config *config, t_application *application, t_vector square_pos);

void			cube_print_map(t_config *config, t_application *application);

int             event_gen(int keycode, t_application *application); //creat hook.c with global

void			render_application(t_config *config, t_application *application);
int				run_application(t_application *application);
#endif