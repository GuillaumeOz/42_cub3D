/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_key_handler.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:10:40 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/03 21:23:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_KEY_HANDLER_H
# define CUBE3D_KEY_HANDLER_H

typedef         void (*controler)(int key, int32_t control);

typedef struct	s_cube3d_key_handler
{
	int		marker_control;
	void	(*controler)(int32_t control, void *param)
}				t_cube3d_key_handler;

enum	e_cube3d_control_handler
{
	NOCONTRL = 0,
	PLAYERCONTRL = (2147483648>>0),
	CAMERACONTRL = (2147483648>>1),
	SPEEDBONUS = (2147483648>>2)
};

enum	e_cube3d_control_set
{
	NOEVENTMASK = 0,
	PLAYER_MARKER = (2147483648>>0),
	A_KEYPRESS = (1<<0),
	D_KEYPRESS = (1<<1),
	W_KEYPRESS = (1<<2),
	S_KEYPRESS = (1<<3),
	CAMERA_MARKER = (2147483648>>1),
	LEFT_KEYPRESS = (1<<3),
	RIGHT_KEYPRESS = (1<<4),
	SPEED_MARKER = (2147483648>>2),
	BONUS_SPEEDUP_KEYPRESS = (1<<5),
	BONUS_SPEEDDOWN_KEYPRESS = (1<<6)
};

void    cube3d_key_manager(int key, void *param);
void    player_control();
void    camera_control();
void    speed_control();

/*
**  Build the 3 functions 
**  here
*/

#endif