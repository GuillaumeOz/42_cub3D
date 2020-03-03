/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_key_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/03 21:23:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_cube3d_key_handler g_cube3d_key_handler [] =
{
	{ PLAYERCONTRL, &player_control},
	{ CAMERACONTRL, &camera_control},
	{ SPEEDBONUS, &speed_control},
	{ NOCONTRL, NULL}//build the controlers functions
};

void	cube3d_key_manager(int key, void *param)
{
	// t_player		*player;
	// t_funct			*tab;
	// float			step;
	// float			speed;
	// static float	rotation_speed = 10; // move this part in controler funct
	
	// step = 0.8;
	// player = (t_player*)param;

	int32_t	control;
	int		i;

	control = NOEVENTMASK;
	i = -1;
	if (key == ESC_KEY)
		close_application();
	if (key == A_KEY)
		control |= (A_KEYPRESS, PLAYER_MARKER);
	if (key == D_KEY)
		control |= (D_KEYPRESS, PLAYER_MARKER);
	if (key == W_KEY)
		control |= (A_KEYPRESS, PLAYER_MARKER);
	if (key == S_KEY)
		control |= (A_KEYPRESS, PLAYER_MARKER);
	if (key == LEFT_KEY)
		control |= (LEFT_KEYPRESS, CAMERA_MARKER);
	if (key == RIGHT_KEY)
		control |= (RIGHT_KEYPRESS, CAMERA_MARKER);
	if (key == NK4_KEY && step > 1)// change the condition here later --> create a static function in speed control
		control |= (BONUS_SPEEDDOWN_KEYPRESS, SPEEDBONUS);
	if (key == NK6_KEY && step < 10)// same
		control |= (BONUS_SPEEDUP_KEYPRESS, SPEEDBONUS);
	while (g_cube3d_key_handler[++i].marker_control != NOCONTRL)
		if (control & g_cube3d_key_handler[i].marker_control)
			g_cube3d_key_handler[i].controler(control, param);
}
