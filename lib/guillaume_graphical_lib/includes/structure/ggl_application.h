/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_application.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:48:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 15:38:59 by gozsertt         ###   ########.fr       */
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

typedef int		(*t_key_funct)(int key, void *param);
typedef int		(*t_render_funct)(void *param);
typedef int		(*t_exit_funct)(void);

void			start_application(int size_x, int size_y, char *title);
void			close_application(void);

void			set_pixel(t_vector2 pos, t_color color);
void			clear_screen(void);
void			clear_application(t_color color);
void			application_create_content(void);
void			resize_application(int size_x, int size_y);
void			render_application(void);
int				run_application(void);

void			add_interaction_to_application(t_key_funct funct, int event,
					int maskevent, void *param);
void			add_interaction_exit_control(t_exit_funct funct, int event);
void			application_update(t_render_funct funct, void *param);
void			render_application(void);

#endif
