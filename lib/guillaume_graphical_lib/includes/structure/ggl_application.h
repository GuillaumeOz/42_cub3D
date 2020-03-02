/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_application.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:48:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/25 19:53:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_APPLICATION_H
# define GGL_APPLICATION_H

typedef struct	s_application
{
	char		*title;
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector2	size;
	t_image		*image;
}				t_application;

typedef 		int (*t_key_funct)(int key, void *param);
typedef 		int (*t_render_funct)(void *param);

void			start_application(int size_x, int size_y, char *title);
void			close_application();

void			clear_application(t_color color);
void			application_create_content();
void			resize_application(int size_x, int size_y);
void			render_application();
int				run_application();

void			application_create_content();
void			render_application();
void			render_funct_application(t_render_funct funct, void *param);
void			add_interaction_to_application(int event, t_key_funct funct,
				void *param);

#endif