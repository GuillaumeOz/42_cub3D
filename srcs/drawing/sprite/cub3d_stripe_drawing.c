/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_stripe_drawing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:33:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:35:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_sprite_pixel(t_application *app, int x, int y, t_color color)
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

void	apply_sprite_fog_war(t_sprite_calc *sprite_calc,
	t_sprite_list *current_sprite, t_color *color)
{
	float	tmp;

	current_sprite->fog_war = 0;
	tmp = sprite_calc->sprite_dist[sprite_calc->i];
	while (current_sprite->fog_war < (int)tmp
		&& current_sprite->fog_war <= 255)
		current_sprite->fog_war += 25.5;
	if (color->r - current_sprite->fog_war > 0)
		color->r = color->r - current_sprite->fog_war;
	else
		color->r = 0;
	if (color->g - current_sprite->fog_war > 0)
		color->g = color->g - current_sprite->fog_war;
	else
		color->g = 0;
	if (color->b - current_sprite->fog_war > 0)
		color->b = color->b - current_sprite->fog_war;
	else
		color->b = 0;
	if (color->a - current_sprite->fog_war > 0)
		color->a = color->a - current_sprite->fog_war;
	else
		color->a = 0;
}

void	stripe_drawing(t_sprite_calc *sprite_calc, t_engine *engine,
	t_sprite_list *current_sprite, t_sprite *sprite_tex)
{
	t_color	color;
	int		scaling;

	sprite_calc->screen_pos.y = sprite_calc->draw_y_axis.x;
	while (sprite_calc->screen_pos.y < sprite_calc->draw_y_axis.y)
	{
		scaling = (sprite_calc->screen_pos.y - current_sprite->sprite_z) * 256
			- engine->resolution.y * 128 + current_sprite->sprite_height * 128;
		sprite_calc->tex_pos.y = ((scaling * sprite_tex->tex_resolution.y)
				/ current_sprite->sprite_height) / 256;
		if (texel_is_displayable(sprite_calc,
				current_sprite, sprite_tex) == true)
		{
			color = int_to_color(sprite_tex->pixels[
					sprite_tex->tex_resolution.y * sprite_calc->tex_pos.y
					+ sprite_calc->tex_pos.x]);
			apply_sprite_fog_war(sprite_calc, current_sprite, &color);
			put_sprite_pixel(engine->app, sprite_calc->screen_pos.x,
				sprite_calc->screen_pos.y, color);
		}
		sprite_calc->screen_pos.y++;
	}
}
