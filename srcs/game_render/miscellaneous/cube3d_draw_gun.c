/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw_gun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:51:35 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 16:41:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	put_image(int num[4], t_map map, t_image **img, float time)
{
	while (num[0] < map.resolution.x * 0.6)
	{
		num[2] = (int)((num[0] / (map.resolution.x * 0.6)) *
		img[(int)time]->size.x) * (img[(int)time]->bits_per_pixels / 8);
		num[3] = num[2];
		while (num[1] < map.resolution.y * 0.55)
		{
			if (img[(int)time]->pixels[num[3] + 2] != 0 ||
				img[(int)time]->pixels[num[3] + 1] != 0 ||
				img[(int)time]->pixels[num[3]] != 0)
				put_pixel(g_app->image,
					create_vector2(num[0] + map.resolution.x * 0.6,
					num[1] + map.resolution.y * 0.55),
					create_color(img[(int)time]->pixels[num[3] + 2],
					img[(int)time]->pixels[num[3] + 1],
					img[(int)time]->pixels[num[3]], 255));
			num[1]++;
			num[3] = (int)((num[1] / (map.resolution.y * 0.55)) *
			img[(int)time]->size.y) * img[(int)time]->size.x *
			(img[(int)time]->bits_per_pixels / 8) + num[2];
		}
		num[0]++;
		num[1] = 0;
	}
}

void		draw_gun(t_map map, t_player *hero)
{
	static t_image	*img[2] = {
		NULL,
		NULL
	};
	static float	time = 0;
	int				num[4];

	if (img[0] == NULL)
		img[0] = malloc_image_from_file("textures/gun.xpm");
	if (img[1] == NULL)
		img[1] = malloc_image_from_file("textures/gun_fire.xpm");
	num[0] = 0;
	num[1] = 0;
	if (hero->control & FIRE_MAKER && time <= 0)
		time = 1;	
	put_image(num, map, img, time);
	if (hero->control & FIRE_MAKER)
		time -= 0.5;
	if (!(hero->control & FIRE_MAKER))
		time = 0;
}
