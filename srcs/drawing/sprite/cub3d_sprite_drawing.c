/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_drawing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:38:38 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:34:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	stripe_is_displayable(t_sprite_calc *sprite_calc,
	int x_stripe, t_engine *engine)
{
	if (sprite_calc->inv_transform.y > 0 && x_stripe > 0
		&& x_stripe < engine->resolution.x
		&& sprite_calc->inv_transform.y < engine->wall_limit[x_stripe])
		return (true);
	return (false);
}

static void	draw_right_direction(t_sprite_calc *sprite_calc, t_engine *engine,
	t_sprite_list *current_sprite, t_sprite	*sprite_tex)
{
	sprite_calc->screen_pos.x = sprite_calc->draw_x_axis.x;
	while (sprite_calc->screen_pos.x < sprite_calc->draw_x_axis.y)
	{
		sprite_calc->tex_pos.x = (int)(256 * (sprite_calc->screen_pos.x
					- (-(current_sprite->sprite_width) / 2
						+ sprite_calc->sprite_screen_x))
				* sprite_tex->tex_resolution.x
				/ current_sprite->sprite_width) / 256;
		if (stripe_is_displayable(sprite_calc,
				sprite_calc->screen_pos.x, engine) == true)
			stripe_drawing(sprite_calc, engine, current_sprite, sprite_tex);
		sprite_calc->screen_pos.x++;
	}
}

static void	draw_inverse_direction(t_sprite_calc *sprite_calc, t_engine *engine,
	t_sprite_list *current_sprite, t_sprite	*sprite_tex)
{
	sprite_calc->screen_pos.x = sprite_calc->draw_x_axis.x;
	while (sprite_calc->screen_pos.x < sprite_calc->draw_x_axis.y)
	{
		sprite_calc->tex_pos.x = (int)(256 * ((sprite_calc->draw_x_axis.y
						- sprite_calc->screen_pos.x)
					- (-(current_sprite->sprite_width)
						/ 2 + (sprite_calc->draw_x_axis.y
							- sprite_calc->sprite_screen_x)))
				* sprite_tex->tex_resolution.x
				/ current_sprite->sprite_width) / 256;
		if (stripe_is_displayable(sprite_calc,
				sprite_calc->screen_pos.x, engine) == true)
			stripe_drawing(sprite_calc, engine, current_sprite, sprite_tex);
		sprite_calc->screen_pos.x++;
	}	
}

void	sprite_drawing(t_sprite_calc *sprite_calc, t_engine *engine,
	t_sprite_list *current_sprite, t_sprite	*sprite_tex)
{
	if (current_sprite->animation < 5)
	{
		draw_right_direction(sprite_calc, engine, current_sprite, sprite_tex);
		current_sprite->animation += 1;
	}
	else
	{
		draw_inverse_direction(sprite_calc, engine,
			current_sprite, sprite_tex);
		current_sprite->animation += 1;
		if (current_sprite->animation > 10)
			current_sprite->animation = 0;
	}
}
