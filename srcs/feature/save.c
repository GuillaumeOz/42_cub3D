/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 22:21:01 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/06 13:38:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	write_bmp_header(int fd, int filesize)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = g_app->size.x;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = g_app->size.y;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	get_color(int x, int y)
{
//	int	rgb;
	int	color;

	color = *(int*)(g_app->image->pixels + (4 * (int)g_app->size.x *
				((int)g_app->size.y - 1 - y)) + (4 * x));
//	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (color);
}

static int	write_bmp_data(int fd)
{
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)g_app->size.y)
	{
		j = 0;
		while (j < (int)g_app->size.x)
		{
			color = get_color(j, i);
			if (write(fd, &color, 3) < 0)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int			save_bmp(t_game_engine *engine, t_map *map, t_player *hero)
{
	int			filesize;
	int			file;

	PRINTV(map->size.x, map->size.y);
	hero->forward = create_vector2((((int)(hero->size) - 1) *
												cos(hero->pitch) + hero->pos.x),
				((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	draw_map(engine);
//	draw_gun(*map, hero);
//	draw_hud(*map);
//	draw_2d_map(map, hero);
//	draw_health_bar(*map, *hero);
	filesize = 54 + (3 * (int)g_app->size.x *
						(int)g_app->size.y);
	file = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	if (file < 0)
		return (FAILURE);
	if (!write_bmp_header(file, filesize))
		return (FAILURE);
	if (!write_bmp_data(file))
		return (FAILURE);
	close(file);
	return (SUCCESS);
}