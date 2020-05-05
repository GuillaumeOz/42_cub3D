/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_game_over.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:51:43 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 17:02:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_game_over(t_map map)
{
	static t_image	*img = NULL;
	int				num[4];

	if (img == NULL)
		img = malloc_image_from_file("textures/game_over.xpm");
	num[0] = 0;
	num[1] = 0;
	while (num[0] < map.resolution.x)
	{
		num[2] = (int)((num[0] / map.resolution.x) * img->size.x) *
												(img->bits_per_pixels / 8);
		num[3] = num[2];
		while (num[1] < map.resolution.y)
		{
			put_pixel(g_app->image, create_vector2(num[0], num[1]),
			create_color(img->pixels[num[3] + 2], img->pixels[num[3] + 1],
						img->pixels[num[3]], 200));
			num[3] = (int)((num[1] / map.resolution.y) * img->size.y) *
								img->size.x * (img->bits_per_pixels / 8) +
									num[2];
			num[1]++;
		}
		num[0]++;
		num[1] = 0;
	}
}
