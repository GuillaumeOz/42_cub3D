/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_monster.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:16:00 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 15:50:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_MONSTER_H
# define CUBE3D_MONSTER_H

typedef struct	s_monster
{
	t_texture 	life;
	t_texture 	dead;
	int			damage;
}				t_monster;

t_monster		create_monster(char *p_life, char *p_dead, int p_dmg);
void			destroy_monster(t_monster p_to_destroy);

#endif
