/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_key_handler.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:10:40 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/16 18:50:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_KEY_HANDLER_H
# define CUBE3D_KEY_HANDLER_H

# define ONEFROMLEFT 2147483648

typedef struct	s_cube3d_key_handler
{
	int		marker_control;
	void	(*controler)(int32_t control, void *param);
}				t_cube3d_key_handler;

enum	e_cube3d_control_handler
{
	NOCONTRL = 0,
	PLAYERCONTRL = (ONEFROMLEFT>>0),
	CAMERACONTRL = (ONEFROMLEFT>>1),
	SPEEDBONUS = (ONEFROMLEFT>>2),
	FIRECONTRL = (ONEFROMLEFT>>3)
};

enum	e_cube3d_control_set
{
	NOEVENTMASK = 0,
	PLAYER_MARKER = (ONEFROMLEFT>>0),
	A_KEYPRESS = (1<<0),
	D_KEYPRESS = (1<<1),
	W_KEYPRESS = (1<<2),
	S_KEYPRESS = (1<<3),
	CAMERA_MARKER = (ONEFROMLEFT>>1),
	LEFT_KEYPRESS = (1<<3),
	RIGHT_KEYPRESS = (1<<4),
	SPEED_MARKER = (ONEFROMLEFT>>2),
	BONUS_SPEEDUP_KEYPRESS = (1<<5),
	FIRE_MAKER = (ONEFROMLEFT>>3),
	FIRE_KEYPRESS = (1<<5),
	INTERACT_MAKER = (ONEFROMLEFT>>4),
	INTERACT_KEYPRESS = (1<<6)
};

int		cube3d_key_released_manager(int key, void *param);
int		cube3d_key_press_manager(int key, void *param);

//put this in another .c file
void    player_control(int32_t control, void* param);
void    camera_control(int32_t control, void* param);
void    speed_control(int32_t control, void* param);

#endif