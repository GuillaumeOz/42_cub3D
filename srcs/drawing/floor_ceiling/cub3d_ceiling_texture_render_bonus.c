/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ceiling_texture_render_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:36:53 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:07:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_ceiling_pixel(t_application *app, int x, int y, t_color color)
{
	t_image	*image;
	char	*tmp;

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

static void	apply_ceiling_fog_war(int fog_war, t_color *color)
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

static void	set_ceiling_fract(t_floor_calc *floor_calc,
	t_int_vector2 tex_resolution)
{
	floor_calc->ceiling_fract = create_int_vector2((int)(tex_resolution.x
				* (floor_calc->floor.x - floor_calc->cell.x))
			& (tex_resolution.x - 1), (int)(tex_resolution.y
				* (floor_calc->floor.y - floor_calc->cell.y))
			& (tex_resolution.y - 1));
}

void	ceiling_texture_render_bonus(t_floor_calc floor_calc,
	t_engine *engine, int x, int y)
{
	int				*ceiling_pixels;
	t_color			color;
	t_int_vector2	tex_resolution;

	ceiling_pixels = engine->ceiling_texture->pixels;
	tex_resolution = engine->ceiling_texture->tex_resolution;
	set_ceiling_fract(&floor_calc, tex_resolution);
	color = int_to_color(ceiling_pixels[tex_resolution.y
			* floor_calc.ceiling_fract.y + floor_calc.ceiling_fract.x]);
	apply_ceiling_fog_war(floor_calc.fog_war, &color);
	put_ceiling_pixel(engine->app, x, engine->resolution.y - y - 1, color);
}
