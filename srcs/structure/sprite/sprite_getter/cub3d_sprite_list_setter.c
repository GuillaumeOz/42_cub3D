/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_list_setter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:09:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:15:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite_list_id(t_list *sprite_list, int i, bool value)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	current_sprite->id = value;
}

void	set_sprite_list_dist(t_list *sprite_list, int i, double value)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	current_sprite->dist = value;
}

void	set_sprite_list_width_axis(t_list *sprite_list, int i, double value)
{
	t_sprite_list	*current_sprite;
	double			new_value;

	current_sprite = list_at(sprite_list, i);
	new_value = current_sprite->sprite_width_axis + value;
	if (new_value > 0.5f && new_value < 10)
		current_sprite->sprite_width_axis = new_value;
}

void	set_sprite_list_height_axis(t_list *sprite_list, int i, double value)
{
	t_sprite_list	*current_sprite;
	double			new_value;

	current_sprite = list_at(sprite_list, i);
	new_value = current_sprite->sprite_height_axis + value;
	if (new_value > 0.5f && new_value < 10)
		current_sprite->sprite_height_axis = new_value;
}

void	set_sprite_list_z_axis(t_list *sprite_list, int i, double value)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	current_sprite->sprite_z_axis += value;
}
