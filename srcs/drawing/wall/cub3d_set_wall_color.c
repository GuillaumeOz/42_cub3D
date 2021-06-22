/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_wall_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:18:45 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:16:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_wall_int_to_convert(t_wall_calc *wall_calc,
	int *pixels, int offset)
{
	int	color;

	color = pixels[offset * wall_calc->tex.y + wall_calc->tex.x];
	return (color);
}

static void	set_current_offset(int *current_offset, t_wall_calc *wall_calc)
{
	if (wall_calc->hit_char == 'a')
		*current_offset = 0;
	else if (wall_calc->hit_char == 'b')
		*current_offset = 1;
	else if (wall_calc->hit_char == 'c')
		*current_offset = 2;
	else if (wall_calc->hit_char == 'd')
		*current_offset = 3;
	else if (wall_calc->hit_char == 'e')
		*current_offset = 4;
	else if (wall_calc->hit_char == 'f')
		*current_offset = 5;
	else if (wall_calc->hit_char == 'g')
		*current_offset = 6;
	else if (wall_calc->hit_char == 'h')
		*current_offset = 7;
	else if (wall_calc->hit_char == 'i')
		*current_offset = 8;
	else if (wall_calc->hit_char == 'j')
		*current_offset = 9;
	else if (wall_calc->hit_char == 'k')
		*current_offset = 10;
}

static int	set_secret_door_int_to_convert(t_wall_calc *wall_calc,
	int *pixels, int res_x)
{
	int	single_offset;
	int	current_offset;
	int	result_offset;
	int	color;

	single_offset = res_x / 11;
	set_current_offset(&current_offset, wall_calc);
	result_offset = current_offset * single_offset;
	color = pixels[res_x * wall_calc->tex.y
		+ result_offset + wall_calc->tex.x];
	return (color);
}

void	set_wall_color(t_engine *engine, t_wall_calc *wall_calc,
	t_color *color)
{
	t_texture			*texture;
	int					to_convert;

	if (wall_calc->hit_char == '1')
	{
		texture = engine->texture[wall_calc->id];
		to_convert = set_wall_int_to_convert(wall_calc,
				texture->pixels, texture->tex_resolution.y);
		*color = int_to_color(to_convert);
	}
	else
	{
		texture = engine->secret_door;
		to_convert = set_secret_door_int_to_convert(wall_calc,
				texture->pixels, texture->tex_resolution.x);
		*color = int_to_color(to_convert);
	}
}
