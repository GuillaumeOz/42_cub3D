/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_list_getter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:16:38 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:21:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite_id	get_sprite_list_id(t_list *sprite_list, int i)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	return (current_sprite->id);
}

t_float_vector2	get_sprite_list_coord(t_list *sprite_list, int i)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	return (current_sprite->coord);
}

double	get_sprite_list_dist(t_list *sprite_list, int i)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	return (current_sprite->dist);
}

bool	get_sprite_list_enable(t_list *sprite_list, int i)
{
	t_sprite_list	*current_sprite;

	current_sprite = list_at(sprite_list, i);
	return (current_sprite->enable);
}
