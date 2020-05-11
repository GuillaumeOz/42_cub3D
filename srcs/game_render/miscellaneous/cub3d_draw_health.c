/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_health.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:51:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/10 16:39:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	g_life[][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0},
	{1, 0, 1, 0, 1, 0},
	{1, 0, 1, 0, 1, 0},
	{1, 1, 0, 1, 1, 0},
	{1, 1, 0, 1, 1, 1},
	{1, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1}
};

static void	put_image(int var[4], t_map map, t_image **img, int *num)
{
	while (var[0] < map.resolution.x * 0.05)
	{
		var[2] = (int)((var[0] / (map.resolution.x * 0.05)) *
		img[g_life[num[2]][num[1]]]->size.x) *
		(img[g_life[num[2]][num[1]]]->bits_per_pixels / 8);
		var[3] = var[2];
		while (var[1] < map.resolution.y * 0.09)
		{
			if (img[g_life[num[2]][num[1]]]->pixels[var[3] + 2] != 0 ||
				img[g_life[num[2]][num[1]]]->pixels[var[3] + 1] != 0 ||
				img[g_life[num[2]][num[1]]]->pixels[var[3]] != 0)
				put_pixel(g_app->image, create_vector2(var[0] + 0.05 *
				map.resolution.x * num[1], var[1] + map.resolution.y * 0.095),
				create_color(img[g_life[num[2]][num[1]]]->pixels[var[3] + 2],
				img[g_life[num[2]][num[1]]]->pixels[var[3] + 1],
				img[g_life[num[2]][num[1]]]->pixels[var[3]], 255));
			var[1]++;
			var[3] = (int)((var[1] / (map.resolution.y * 0.09)) *
			img[g_life[num[2]][num[1]]]->size.y) *
			img[g_life[num[2]][num[1]]]->size.x *
			(img[g_life[num[2]][num[1]]]->bits_per_pixels / 8) + var[2];
		}
		var[0]++;
		var[1] = 0;
	}
}

static void	draw_other_image(int var[4], t_map map, t_image **img, int *num)
{
	var[0] = 0;
	var[1] = 0;
	num[1] = 0;
	while (num[1] < num[0])
	{
		put_image(var, map, img, num);
		num[1]++;
		var[0] = 0;
		var[1] = 0;
	}
	num[1] += 1;
	while (num[1] > num[0] && num[1] < 6)
	{
		put_image(var, map, img, num);
		num[1]++;
		var[0] = 0;
		var[1] = 0;
	}
}

static void	put_last_image(int var[4], t_map map, t_image **img, int *num)
{
	var[2] = (int)((var[0] / (map.resolution.x * 0.05)) * img[g_life[num[2]]
	[num[0]]]->size.x) * (img[g_life[num[2]][num[0]]]->bits_per_pixels / 8);
	var[3] = var[2];
	while (var[1]++ < map.resolution.y * 0.09)
	{
		if (img[g_life[num[2]][num[0]]]->pixels[var[3] + 2] != 0 ||
			img[g_life[num[2]][num[0]]]->pixels[var[3] + 1] != 0 ||
			img[g_life[num[2]][num[0]]]->pixels[var[3]] != 0)
			put_pixel(g_app->image, create_vector2(var[0] + map.resolution.x *
			0.05 * num[0], var[1] + map.resolution.y * 0.095),
			create_color(img[g_life[num[2]][num[0]]]->pixels[var[3] + 2],
			img[g_life[num[2]][num[0]]]->pixels[var[3] + 1],
			img[g_life[num[2]][num[0]]]->pixels[var[3]], 255));
		var[3] = (int)((var[1] / (map.resolution.y * 0.09)) *
		img[g_life[num[2]][num[0]]]->size.y) *
		img[g_life[num[2]][num[0]]]->size.x *
		(img[g_life[num[2]][num[0]]]->bits_per_pixels / 8) + var[2];
	}
	var[0]++;
	var[1] = 0;
}

static void	end(float *percent, int *num, t_player hero)
{
	if (*percent >= 1)
	{
		*percent = 0;
		num[2] = (hero.hp / 100.0f) * 10;
		num[0]++;
	}
	if (num[0] == 6)
		num[0] = 0;
}

void		draw_health_bar(t_map map, t_player hero)
{
	static float	percent = 0;
	static t_image	*img[2] = {
		NULL,
		NULL
	};
	static int		num[3] = {0, 0, 10};
	int				var[4];

	if (img[1] == NULL)
		img[1] = malloc_image_from_file("textures/pics.xpm");
	if (img[0] == NULL)
		img[0] = malloc_image_from_file("textures/plat.xpm");
	draw_other_image(var, map, img, num);
	percent += 0.4;
	while (var[0] < map.resolution.x * 0.05)
	{
		put_last_image(var, map, img, num);
		if (percent < (var[0] / (map.resolution.x * 0.05)))
			break ;
	}
	end(&percent, num, hero);
}
