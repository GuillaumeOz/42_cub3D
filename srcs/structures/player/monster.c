/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:21:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 14:52:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_monster	create_monster(char *p_life, char *p_dead, int p_dmg)
{
	t_monster result;

	result.life = create_texture(p_life);
	result.dead = create_texture(p_dead);
	result.damage = p_dmg;
	return (result);
}

void		destroy_monster(t_monster p_to_destroy)
{
	destroy_texture(p_to_destroy.life);
	destroy_texture(p_to_destroy.dead);
}
