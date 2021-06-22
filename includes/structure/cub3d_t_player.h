/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_player.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:06:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/16 18:18:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_PLAYER_H
# define CUB3D_T_PLAYER_H

typedef enum e_player_dir
{
	NORTH_DIR,
	SOUTH_DIR,
	EAST_DIR,
	WEST_DIR,
}				t_player_dir;

typedef struct s_player
{
	t_double_vector2	pos;
	t_double_vector2	old_dir;
	t_double_vector2	dir;
	t_double_vector2	old_plane;
	t_double_vector2	plane;
	int					mouse_pos;
	double				move_speed;
	double				rot_speed;
	t_time				*time;
	t_uint32			control;
}				t_player;

t_player		*malloc_player(double pos_x, double pos_y, t_player_dir dir);
t_player		create_player(double pos_x, double pos_y, t_player_dir dir);
void			destroy_player(t_player to_destroy);
void			free_player(t_player *to_free);

#endif