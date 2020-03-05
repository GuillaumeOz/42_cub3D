/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_key_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/05 20:04:31 by gozsertt         ###   ########.fr       */
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

static	bool	*hit_player_wall(t_map *map, t_vector2 pos)
{
	int x;
	int y;

	x = (int)(pos.x);
	y = (int)(pos.y);

	if (map->board[x][y]->type == wall)
		return (true);
	return (false);
}

void	player_hitbox(t_map *map, t_vector2 pos, float step)
{
	float dot;

	dot = 0.1f;
	if (hit_player_wall(map, create_vector2(pos.x, pos.y + dot)) == true)
		pos.y -= step;
	if (hit_player_wall(map, create_vector2(pos.x + dot, pos.y)) == true)
		pos.x -= step;
	if (hit_player_wall(map, create_vector2(pos.x, pos.y - dot)) == true)
		pos.y += step;
	if (hit_player_wall(map, create_vector2(pos.x - dot, pos.y)) == true)
		pos.x += step;
}

void    speed_control(int32_t control, void* param)
{
	// float			speed;
	// static float	rotation_speed = 10; // move this part in speed controler funct
	
}

void    camera_control(int32_t control, void* param)
{
	
}

void    player_control(int32_t control, void *param)
{
	t_game_engine	*modifier;
	t_player		*player;
	t_map			*map;

	modifier = (t_game_engine*)param;
	player = (t_player*)modifier->player;
	map = (t_map*)modifier->map;
	if (control & W_KEYPRESS)
		player_hitbox(map, add_vector2_to_vector2(player->pos, 
			create_vector2(0.0f, player->step)), player->step);
	if (control & A_KEYPRESS)
		player_hitbox(map, substract_vector2_to_vector2(player->pos,
			create_vector2(player->step, 0.0f)), player->step);
	if (control & D_KEYPRESS)
		player_hitbox(map, add_vector2_to_vector2(player->pos,
			create_vector2(player->step, 0.0f)), player->step);
	if (control & S_KEYPRESS)
		player_hitbox(map, substract_vector2_to_vector2(player->pos,
			create_vector2(0.0f, player->step)), player->step);
}

static	void	key_loader(int key, int32_t *control)
{
	if (key == ESC_KEY)
		close_application();
	if (key == A_KEY)
		*control |= (A_KEYPRESS, PLAYER_MARKER);
	if (key == D_KEY)
		*control |= (D_KEYPRESS, PLAYER_MARKER);
	if (key == W_KEY)
		*control |= (W_KEYPRESS, PLAYER_MARKER);
	if (key == S_KEY)
		*control |= (S_KEYPRESS, PLAYER_MARKER);
	if (key == LEFT_KEY)
		*control |= (LEFT_KEYPRESS, CAMERA_MARKER);
	if (key == RIGHT_KEY)
		*control |= (RIGHT_KEYPRESS, CAMERA_MARKER);
	if (key == NK4_KEY && step > 1)// change the condition here later --> with the step in the struct
		*control |= (BONUS_SPEEDDOWN_KEYPRESS, SPEEDBONUS);
	if (key == NK6_KEY && step < 10)// same
		*control |= (BONUS_SPEEDUP_KEYPRESS, SPEEDBONUS);
	return(*control);
}

void			cube3d_key_manager(int key, void *param)
{
	int32_t	control;
	int		i;

	control = NOEVENTMASK;
	i = -1;
	key_loader(key, &control);
	while (g_cube3d_key_handler[++i].marker_control != NOCONTRL)
		if (control & g_cube3d_key_handler[i].marker_control)
			g_cube3d_key_handler[i].controler(control, param);
}
