/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event_manager.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:24:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 22:07:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EVENT_MANAGER_H
# define CUB3D_EVENT_MANAGER_H

//EVENT MANAGER

# define ONELEFTMASK 2147483648

enum	e_cub3d_event
{
	NO_CTRL = 0,
	W_CTRL = (1 << 0),
	A_CTRL = (1 << 1),
	S_CTRL = (1 << 2),
	D_CTRL = (1 << 3),
	LEFT_CTRL = (1 << 4),
	RIGHT_CTRL = (1 << 5),
	LSFT_CTRL = (1 << 6),
	RSFT_CTRL = (1 << 7),
	Q_CTRL = (1 << 8),
	E_CTRL = (1 << 9),
	U_CTRL = (1 << 10),
	J_CTRL = (1 << 11),
	I_CTRL = (1 << 12),
	K_CTRL = (1 << 13),
	O_CTRL = (1 << 14),
	L_CTRL = (1 << 15),
	MOVE_MARKER = (ONELEFTMASK >> 0),
	SPEED_MARKER = (ONELEFTMASK >> 1),
	CAMERA_MARKER = (ONELEFTMASK >> 2),
	FIRE_MARKER = (ONELEFTMASK >> 3),
	ACTION_MARKER = (ONELEFTMASK >> 4),
	MOUSE_MARKER = (ONELEFTMASK >> 5),
	TRANSFORM_MARKER = (ONELEFTMASK >> 6),
};

void	sprite_width_transformation(int key, t_player *player);
void	sprite_height_transformation(int key, t_player *player);
void	sprite_z_transformation(int key, t_player *player);

void	sprite_transformation_remover(int key, t_player *player);
void	sprite_transformation_loader(int key, t_player *player);

bool	hitbox(double x, double y, t_list *map_list);
void	player_move(t_player *player, t_list *map_list);

void	camera_keyboard_move(t_player *player);
int		camera_mouse_move_bonus(int x, int y, void *param);
void	camera_move(t_engine *engine, t_player *player);

int		key_release(int key, void *param);
int		key_press(int key, void *param);

void	event_manager(t_engine *engine);

#endif