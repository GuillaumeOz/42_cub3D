/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:24:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/04 11:33:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_COLOR_H
# define CUBE3D_COLOR_H

typedef unsigned char uchar_;

typedef struct	s_color
{
	uchar_	b;
	uchar_	g;
	uchar_	r;
	uchar_	t;
}				t_color;

t_color		*malloc_color(uchar_ b, uchar_ g, uchar_ r, uchar_ t);
t_color		create_color(uchar_ b, uchar_ g, uchar_ r, uchar_ t);
void		destroy_color(t_color to_destroy);
void		free_color(t_color *to_free);
int			convert_color(t_color color);

#endif