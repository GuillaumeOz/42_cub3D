/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:32:16 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/20 17:24:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_player	create_player(t_vector2 p_pos, t_direction p_dir)
{
	return (create_actor(p_pos, ally, p_dir));
}

t_player	*malloc_player(t_vector2 p_pos, t_direction p_dir)
{
	return (malloc_actor(p_pos, ally, p_dir));
}

void   destroy_player(t_player to_destroy)
{
    (void)to_destroy;
}

void   free_player(t_player *to_free)
{
    destroy_player(*to_free);
    free(to_free);
}