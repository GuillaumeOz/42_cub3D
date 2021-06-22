/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_save_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:53:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 16:42:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	quit_bmp(t_engine *engine)
{
	free_engine(engine);
	printf("The cub3d_image.bmp file has been created\n");
	exit(EXIT_SUCCESS);
}

static void	write_bmp_image_data(int fd, t_engine *engine)
{
	int				index;
	unsigned int	*line;
	unsigned int	*tmp_pixels;

	index = 0;
	tmp_pixels = (unsigned int *)engine->app->image->pixels;
	while (index < engine->app->resolution.y)
	{
		line = &tmp_pixels[(engine->app->resolution.y - index - 1)
			*engine->app->image->size_line
			/ (engine->app->image->bits_per_pixels / 8)];
		write(fd, line, engine->app->image->size_line);
		index++;
	}
}

static void	fill_bmp_bitmap(int fd, t_engine *engine, t_bmp_bitmap *bmp_bitmap)
{
	write(fd, "BM", 2);
	bmp_bitmap->file_size = 54 + (engine->app->resolution.x
			* engine->app->resolution.y
			* engine->app->image->bits_per_pixels / 8);
	bmp_bitmap->pixel_offset = 54;
	bmp_bitmap->dib_header_size = 40;
	bmp_bitmap->image_width = engine->app->image->resolution.x;
	bmp_bitmap->image_height = engine->app->image->resolution.y;
	bmp_bitmap->planes = 1;
	bmp_bitmap->bits_per_pixel = engine->app->image->bits_per_pixels;
	bmp_bitmap->image_size = engine->resolution.x * engine->resolution.y
		* (engine->app->image->bits_per_pixels / 8);
	write(fd, bmp_bitmap, sizeof(t_bmp_bitmap));
}

void	save_bmp(t_engine *engine)
{
	t_bmp_bitmap	*bmp_bitmap;
	int				fd;

	fd = open("./cub3d_image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		cub3d_error(ERROR_BMP1, "The cub3d_image.bmp file cannot be create");
	bmp_bitmap = malloc_bmp_bitmap();
	time_render(engine, engine->player);
	event_manager(engine);
	floor_ceiling_render(engine, engine->player);
	wall_render(engine, engine->player);
	sprite_render_bonus(engine, engine->player);
	player_move(engine->player, engine->map);
	camera_move(engine, engine->player);
	fill_bmp_bitmap(fd, engine, bmp_bitmap);
	write_bmp_image_data(fd, engine);
	close (fd);
	quit_bmp(engine);
}
