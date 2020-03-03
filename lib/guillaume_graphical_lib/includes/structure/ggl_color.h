/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:24:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/11 10:56:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_COLOR_H
# define GGL_COLOR_H

typedef unsigned char t_uchar;

typedef struct	s_color
{
	t_uchar	r;
	t_uchar	g;
	t_uchar	b;
	t_uchar	a;
}				t_color;

t_color		*malloc_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a);
t_color		create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a);
void		destroy_color(t_color to_destroy);
void		free_color(t_color *to_free);

t_color		fuze_color(t_color actual, t_color to_add);
#endif