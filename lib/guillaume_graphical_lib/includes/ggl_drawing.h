/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:46:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:59:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_DRAWING_H
# define GGL_DRAWING_H

void			put_pixel(t_image *image, t_vector2 pos, t_color color);
void			draw_line(t_vector2 p_a_b[2], t_color color, float width);

void			draw_rectangle(t_vector2 pos, t_vector2 size, t_color color);
void			draw_rectangle_in_image(t_image *image, t_vector2 pos,
					t_vector2 size, t_color color);

void			draw_circle(t_vector2 pos, int radius, t_color color);
void			draw_circle_in_image(t_image *image, t_vector2 pos,
					int radius, t_color color);
t_vector2_list	calc_circle(t_vector2 center, float radius);

void			draw_line(t_vector2 p_a_b[2], t_color color, float width);
void			draw_line_in_image(t_image *image, t_vector2 pos,
					int radius, t_color color);

#endif
