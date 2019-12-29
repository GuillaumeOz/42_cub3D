/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_application.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:48:07 by gozsertt          #+#    #+#             */
/*   Updated: 2019/12/29 13:07:23 by gozsertt         ###   ########.fr       */
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
}				t_application;

t_application	create_application(int x, int y, char *title);
t_application	*malloc_application(int x, int y, char *title);
void			destroy_application(t_application to_destroy);
void			free_application(t_application *to_free);
int				run_application(t_application *application);

#endif