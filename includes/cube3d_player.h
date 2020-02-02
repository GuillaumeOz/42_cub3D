/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:42:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/30 12:27:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PLAYER_H
# define CUBE3D_PLAYER_H

typedef struct	s_player
{
	struct s_vector	*pos_player;
	float			dir_degree;
	float			dir_radius;
}				t_player;

t_player	*malloc_player(float pos_x, float pos_y, float dir_d, float dir_r);
t_player	create_player(float pos_x, float pos_y, float dir_d, float dir_r);
void		destroy_player(t_player to_destroy);
void		free_player(t_player *to_free);

#endif