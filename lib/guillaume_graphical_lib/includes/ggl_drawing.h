/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:46:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/11 15:42:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_DRAWING_H
# define GGL_DRAWING_H

void	put_pixel(t_image *image, int x, int y, t_color color);

void	draw_rectangle(t_vector2 pos, t_vector2 size, t_color color);
void	draw_rectangle_in_image(t_image *image, t_vector2 pos, t_vector2 size, t_color color);

void	draw_circle(t_vector2 pos, int radius, t_color color);
void	draw_circle_in_image(t_image *image, t_vector2 pos, int radius, t_color color);

#endif