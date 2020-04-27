/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:23:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/27 18:54:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PLAYER_H
# define CUBE3D_PLAYER_H

# define player_speed 1.0f

# define east_pitch 0
# define north_pitch PI / 2
# define west_pitch PI
# define south_pitch (-PI / 2)

typedef enum	e_direction
{
	east = 0,
	north = 1,
	west = 2,
	south = 3
}				t_direction;

typedef struct  s_player
{
	t_vector2   pos;
	
	float		move_speed;
	float		rotation_speed;
	
	t_vector2	movement;
	t_vector2	last_movement;
	
	t_vector2   forward;
	t_vector2   right;
	
	float       fov;
	float       pitch;

	float		radius;
	float       size;
	
	int			hp;

	float       bonus_speed;

	int32_t     control;
}               t_player;

t_player	create_player(t_vector2 p_pos, float p_dir, float speed);
t_player	*malloc_player(t_vector2 p_pos, float p_dir, float speed);
void		destroy_player(t_player to_destroy);
void		free_player(t_player *to_free);

t_player	reset_player(int p_hp);

#endif
