/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall_drawing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:21:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 15:56:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_wall_pixel(t_application *app, int x, int y, t_color color)
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

void	apply_wall_fog_war(t_wall_calc *wall_calc, t_color *color)
{
	float	tmp;

	wall_calc->fog_war = 0;
	tmp = wall_calc->wall_dist * 10;
	while (wall_calc->fog_war < (int)tmp
		&& wall_calc->fog_war <= 255)
		wall_calc->fog_war += 2.55;
	if (color->r - wall_calc->fog_war > 0)
		color->r = color->r - wall_calc->fog_war;
	else
		color->r = 0;
	if (color->g - wall_calc->fog_war > 0)
		color->g = color->g - wall_calc->fog_war;
	else
		color->g = 0;
	if (color->b - wall_calc->fog_war > 0)
		color->b = color->b - wall_calc->fog_war;
	else
		color->b = 0;
	if (color->a - wall_calc->fog_war > 0)
		color->a = color->a - wall_calc->fog_war;
	else
		color->a = 0;
}

void	wall_drawing(t_wall_calc *wall_calc, t_engine *engine,
	t_player *player, int x)
{
	t_color	color;
	int		y;

	set_line_height(wall_calc, engine);
	set_draw_start_end(wall_calc, engine);
	set_wall_x(wall_calc, player);
	set_tex_x_from_wall_x(wall_calc, engine);
	set_tex_step(wall_calc, engine);
	set_tex_pos(wall_calc, engine);
	y = wall_calc->draw_start;
	while (y < wall_calc->draw_end)
	{
		set_tex_y_limit(wall_calc, engine);
		set_update_tex_pos(wall_calc);
		set_wall_color(engine, wall_calc, &color);
		if (BONUS == true)
			apply_wall_fog_war(wall_calc, &color);
		put_wall_pixel(engine->app, x, y, color);
		y++;
	}
	engine->wall_limit[x] = wall_calc->wall_dist;
}
