/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:42:38 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/02 15:11:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_actor		create_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir)
{
	t_actor result;

	result.pos = p_pos;
	result.team = p_team;
	result.angle = (90 * (int)(p_dir));
	return (result);
}

t_actor		*malloc_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir)
{
	t_actor *result;

	result = (t_actor *)malloc(sizeof(t_actor));
	if (result == NULL)
		return (NULL);
	*result = create_actor(p_pos, p_team, p_dir);
	return (result);
}

void		destroy_actor(t_actor to_destroy)
{
	(void)to_destroy;
}

void		free_actor(t_actor *to_free)
{
	destroy_actor(*to_free);
	free(to_free);
}
