/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_floor_texture_render_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:25:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:14:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_floor_pixel(t_application *app, int x, int y, t_color color)
{
	t_image		*image;
	char		*tmp;

	if (x < 0 || x > app->resolution.x
		|| y < 0 || y > app->resolution.y)
		return ;
	image = app->image;
	tmp = image->pixels + (y * image->size_line + x
			* (image->bits_per_pixels / 8));
	tmp[RED_COMP] = color.r;
	tmp[GREEN_COMP] = color.g;
	tmp[BLUE_COMP] = color.b;
	tmp[ALPHA_COMP] = color.a;
}

static void	apply_floor_fog_war(int fog_war, t_color *color)
{
	if (color->r - fog_war > 0)
		color->r = color->r - fog_war;
	else
		color->r = 0;
	if (color->g - fog_war > 0)
		color->g = color->g - fog_war;
	else
		color->g = 0;
	if (color->b - fog_war > 0)
		color->b = color->b - fog_war;
	else
		color->b = 0;
	if (color->a - fog_war > 0)
		color->a = color->a - fog_war;
	else
		color->a = 0;
}

static void	set_floor_fract(t_floor_calc *floor_calc,
	t_int_vector2 tex_resolution)
{
	floor_calc->floor_fract = create_int_vector2((int)(tex_resolution.x
				* (floor_calc->floor.x - floor_calc->cell.x))
			& (tex_resolution.x - 1), (int)(tex_resolution.y
				*(floor_calc->floor.y - floor_calc->cell.y))
			& (tex_resolution.y - 1));
}

void	floor_texture_render_bonus(t_floor_calc floor_calc,
	t_engine *engine, int x, int y)
{
	int				*floor_pixels;
	t_color			color;
	t_int_vector2	tex_resolution;

	floor_pixels = engine->floor_texture->pixels;
	tex_resolution = engine->floor_texture->tex_resolution;
	set_floor_fract(&floor_calc, tex_resolution);
	color = int_to_color(floor_pixels[tex_resolution.x
			* floor_calc.floor_fract.y + floor_calc.floor_fract.x]);
	apply_floor_fog_war(floor_calc.fog_war, &color);
	if (floor_calc.floor_fract.x >= 0 && floor_calc.floor_fract.y >= 0)
		put_floor_pixel(engine->app, x, y, color);
}
