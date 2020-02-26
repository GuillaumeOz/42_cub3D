/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neutral.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:23:59 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/19 19:34:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_neutral	*malloc_neutral(t_vector2 p_pos)
{
	return (malloc_actor(p_pos, neutral, north));
}

t_neutral	create_neutral(t_vector2 p_pos)
{
	return (create_actor(p_pos, neutral, north));
}

void   destroy_neutral(t_neutral to_destroy)
{
    (void)to_destroy;
}

void   free_neutral(t_neutral *to_free)
{
    destroy_neutral(*to_free);
    free(to_free);
}