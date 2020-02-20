/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:23:33 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/19 19:31:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_enemy		create_enemy(t_vector2 p_pos)
{
	return (create_actor(p_pos, enemy, north));
}

t_enemy		*malloc_enemy(t_vector2 p_pos)
{
	return (malloc_actor(p_pos, enemy, north));
}

void   destroy_enemy(t_enemy to_destroy)
{
    (void)to_destroy;
}

void   free_enemy(t_enemy *to_free)
{
    destroy_enemy(*to_free);
    free(to_free);
}
