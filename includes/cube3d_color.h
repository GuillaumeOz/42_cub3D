/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:24:52 by gozsertt          #+#    #+#             */
/*   Updated: 2019/12/30 12:38:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_COLOR_H
# define CUBE3D_COLOR_H

typedef unsigned char uchar_;

typedef struct	s_color
{
	uchar_	r;
	uchar_	g;
	uchar_	b;
}				t_color;

t_color		*malloc_color(uchar_ r, uchar_ g, uchar_ b);
t_color		create_color(uchar_ r, uchar_ g, uchar_ b);
void		destroy_color(t_color to_destroy);
void		free_color(t_color *to_free);
int			convert_color(t_color color);

#endif