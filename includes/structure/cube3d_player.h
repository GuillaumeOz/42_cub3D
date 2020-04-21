/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:23:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/21 13:26:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PLAYER_H
# define CUBE3D_PLAYER_H

# define player_speed 1.0f

typedef struct  s_player
{
	t_vector2   pos;
	int         team;
	float       angle;
	float       speed;
	float       size;
	float       pitch;
	float		radius;
	float       fov;
	int			hp;
	int32_t     control;
	t_vector2	movement;
	t_vector2	last_movement;
	t_vector2   forward;
	t_vector2   right;
}               t_player;

t_player	create_player(t_vector2 p_pos, t_direction p_dir, float speed);
t_player	*malloc_player(t_vector2 p_pos, t_direction p_dir, float speed);
void		destroy_player(t_player to_destroy);
void		free_player(t_player *to_free);

t_player	reset_player(int p_hp);

#endif
