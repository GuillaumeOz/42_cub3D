/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:52:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:28:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	put_pixel(t_image *image, t_vector2 pos, t_color color)
{
	t_color	actual;
	t_color	tmp;
	int		pixel_index;

	if (pos.x < 0 || pos.x >= image->size.x || pos.y < 0 ||
		pos.y >= image->size.y)
		return ;
	pixel_index = convert_2di_1di(pos, g_app->size) * 4;
	actual = create_color(
		image->pixels[pixel_index + RED_COMP],
		image->pixels[pixel_index + GREEN_COMP],
		image->pixels[pixel_index + BLUE_COMP],
		255);
	tmp = fuze_color(actual, color);
	image->pixels[pixel_index + RED_COMP] = tmp.r;
	image->pixels[pixel_index + GREEN_COMP] = tmp.g;
	image->pixels[pixel_index + BLUE_COMP] = tmp.b;
}

void	draw_line(t_vector2 p_a_b[2], t_color color, float width)
{
	t_vector2_list	line;
	t_vector2_list	circle;
	t_vector2		tmps[3];
	size_t			i;
	size_t			j;

	circle = calc_circle(create_vector2(0, 0), width / 2.0f);
	line = calc_line(p_a_b[0], p_a_b[1]);
	i = 0;
	while (i < circle.size)
	{
		tmps[1] = t_vector2_list_at(&circle, i);
		j = 0;
		while (j < line.size)
		{
			tmps[0] = t_vector2_list_at(&line, j);
			tmps[2] = create_vector2(tmps[0].x + tmps[1].x,
														tmps[0].y + tmps[1].y);
			put_pixel(g_app->image, tmps[2], color);
			j++;
		}
		i++;
	}
	destroy_t_vector2_list(circle);
	destroy_t_vector2_list(line);
}
