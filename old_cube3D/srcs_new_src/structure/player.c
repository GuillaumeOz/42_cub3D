/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:26:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/12 17:34:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_player	*malloc_player(float pos_x, float pos_y, float dir_d, float dir_r)
{
	t_player	*player;
	
	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	*player = create_player(pos_x, pos_y, dir_d, dir_r);
	return (player);
}

t_player	create_player(float pos_x, float pos_y, float dir_d, float dir_r)
{
	t_player	player;
	
	player.pos_player = malloc_vector2(pos_x, pos_y);
	player.dir_degree = dir_d;
	player.dir_radius = dir_r;
	return (player);
}

void		destroy_player(t_player to_destroy)
{
	free_vector2(to_destroy.pos_player);
	to_destroy.dir_degree = 0.0;
	to_destroy.dir_radius = 0.0;
}

void		free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}
