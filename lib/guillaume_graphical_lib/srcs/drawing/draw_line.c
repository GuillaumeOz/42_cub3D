/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:52:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/11 15:36:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void put_pixel(t_image *image, int x, int y, t_color color)
{
	t_color actual;
	t_color tmp;
	int pixel_index;

	if (x < 0 || y < 0 || x >= image->size.x || y >= image->size.y)
		return;

	pixel_index = (y * image->size.x + x) * 4;
	actual = create_color(
		image->pixels[pixel_index + RED_COMP],
		image->pixels[pixel_index + GREEN_COMP],
		image->pixels[pixel_index + BLUE_COMP],
		255
	);
	tmp = fuze_color(actual, color);
	image->pixels[pixel_index + RED_COMP] = tmp.r;
	image->pixels[pixel_index + GREEN_COMP] = tmp.g;
	image->pixels[pixel_index + BLUE_COMP] = tmp.b;
}
