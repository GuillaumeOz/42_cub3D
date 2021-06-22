/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_sprite_axis_transformation_bonus.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:02:57 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:06:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	set_sprite_height_area(t_sprite_calc *sprite_calc,
	t_engine *engine, t_sprite_list *current_sprite)
{
	current_sprite->sprite_z = (int)(current_sprite->sprite_z_axis
			/ sprite_calc->inv_transform.y);
	current_sprite->sprite_height = (int)fabs((engine->resolution.y
				/ (sprite_calc->inv_transform.y)))
		/ current_sprite->sprite_height_axis;
	sprite_calc->draw_y_axis.x = -current_sprite->sprite_height / 2
		+ engine->resolution.y / 2 + current_sprite->sprite_z;
	if (sprite_calc->draw_y_axis.x < 0)
		sprite_calc->draw_y_axis.x = 0;
	sprite_calc->draw_y_axis.y = current_sprite->sprite_height / 2
		+ engine->resolution.y / 2 + current_sprite->sprite_z;
	if (sprite_calc->draw_y_axis.y >= engine->resolution.y)
		sprite_calc->draw_y_axis.y = engine->resolution.y - 1;
}

static	void	set_sprite_width_area(t_sprite_calc *sprite_calc,
	t_engine *engine, t_sprite_list *current_sprite)
{
	current_sprite->sprite_width = (int)fabs((engine->resolution.y
				/ (sprite_calc->inv_transform.y)))
		/ current_sprite->sprite_width_axis;
	sprite_calc->draw_x_axis.x = -current_sprite->sprite_width / 2
		+ sprite_calc->sprite_screen_x;
	if (sprite_calc->draw_x_axis.x < 0)
		sprite_calc->draw_x_axis.x = 0;
	sprite_calc->draw_x_axis.y = current_sprite->sprite_width / 2
		+ sprite_calc->sprite_screen_x;
	if (sprite_calc->draw_x_axis.y >= engine->resolution.x)
		sprite_calc->draw_x_axis.y = engine->resolution.x - 1;
}

void	set_sprite_axis_transformation(t_sprite_calc *sprite_calc,
	t_engine *engine, t_sprite_list *current_sprite)
{
	set_sprite_width_area(sprite_calc, engine, current_sprite);
	set_sprite_height_area(sprite_calc, engine, current_sprite);
}
