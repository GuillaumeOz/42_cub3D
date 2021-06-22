/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_display_limit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:50:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:35:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	apply_z_axis_limit(t_sprite_calc *sprite_calc,
	t_sprite_list *current_sprite, float value)
{
	value *= current_sprite->sprite_height_axis;
	if ((sprite_calc->screen_pos.y > sprite_calc->draw_y_axis.x
			- (current_sprite->sprite_z / value))
		&& (sprite_calc->screen_pos.y < sprite_calc->draw_y_axis.y
			- (current_sprite->sprite_z / value)))
		return (false);
	return (true);
}

bool	it_is_z_axis_limit(t_sprite_calc *sprite_calc,
	t_sprite_list *current_sprite)
{
	if (current_sprite->dist < 0.5f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 50) == false)
		return (false);
	else if (current_sprite->dist < 1.0f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 20) == false)
		return (false);
	else if (current_sprite->dist < 1.6f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 6) == false)
		return (false);
	else if (current_sprite->dist < 2.3f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 2.34) == false)
		return (false);
	else if (current_sprite->dist < 3.2f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 1.73) == false)
		return (false);
	else if (current_sprite->dist < 4.0f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 1.42) == false)
		return (false);
	else if (current_sprite->dist < 5.2f
		&& apply_z_axis_limit(sprite_calc, current_sprite, 1.28) == false)
		return (false);
	else if (apply_z_axis_limit(sprite_calc, current_sprite, 1.20) == false)
		return (false);
	return (true);
}

static bool	it_is_black_color(int color)
{
	if ((color & 0x00FFFFFF) != 0)
		return (false);
	return (true);
}

bool	texel_is_displayable(t_sprite_calc *sprite_calc,
	t_sprite_list *current_sprite, t_sprite *sprite_tex)
{
	bool	black_color;
	bool	z_axis_limit;

	black_color = true;
	z_axis_limit = true;
	if (it_is_black_color((sprite_tex->pixels[sprite_tex->tex_resolution.y
					* sprite_calc->tex_pos.y
					+ sprite_calc->tex_pos.x]) == false))
		black_color = false;
	if (it_is_z_axis_limit(sprite_calc, current_sprite) == false)
		z_axis_limit = false;
	if (black_color == false && z_axis_limit == false)
		return (true);
	return (false);
}
