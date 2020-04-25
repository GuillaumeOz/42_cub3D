/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_event_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/25 19:08:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_cube3d_key_handler g_cube3d_key_handler [] =
{
	{ SPEEDBONUS, &speed_control},
	{ PLAYERCONTRL, &player_control},
	{ INTERACTCONTRL, &interact_control},
	{ CAMERACONTRL, &camera_control},
	{ FIRECONTRL, &fire_control},
	{ NOCONTRL, NULL}
};

// RSFT_KEY

static	void	key_loader(int key, t_player *player, int32_t *control,
	 void *param)
{
	if (key == ESC_KEY)
		close_application();
	else if (key == LSFT_KEY)
		*control = (*control | BONUS_SPEEDUP_KEYPRESS) | SPEED_MARKER;
	else if (key == W_KEY)
		*control = (*control | W_KEYPRESS) | PLAYER_MARKER;
	else if (key == A_KEY)
		*control = (*control | A_KEYPRESS) | PLAYER_MARKER;
	else if (key == S_KEY)
		*control = (*control | S_KEYPRESS) | PLAYER_MARKER;
	else if (key == D_KEY)
		*control = (*control | D_KEYPRESS) | PLAYER_MARKER;
	else if (key == LEFT_KEY)
		*control = (*control | LEFT_KEYPRESS) | CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		*control = (*control | RIGHT_KEYPRESS) | CAMERA_MARKER;
	else if ((key == Q_KEY || key == E_KEY) && player->hp > 0)
		player->hp += key == Q_KEY ? -10 : 10;
	else if ((key == RSFT_KEY) && player->hp > 0)
		*control = (*control | FIRE_KEYPRESS) | FIRE_MAKER;
	else if (key == RTN_KEY && player->hp <= 0)
		load_map_control(*control, param);
	else if (key == F_KEY && !(*control & INTERACT_MAKER))
		*control = (*control | INTERACT_KEYPRESS) | INTERACT_MAKER;
}

static void player_marker_remover(int key, int32_t *control)
{
	if (key == W_KEY)
		*control = (*control ^ W_KEYPRESS);
	else if (key == A_KEY)
		*control = (*control ^ A_KEYPRESS);
	else if (key == S_KEY)
		*control = (*control ^ S_KEYPRESS);
	else if (key == D_KEY)
		*control = (*control ^ D_KEYPRESS);
	else
		*control = (*control ^ PLAYER_MARKER);
}

int cube3d_key_release_manager(int key, void *param)
{
	t_player		*player;
	int32_t			*control;

	player = (t_player*)(((void**)param)[1]);
	control = (int32_t*)((int32_t*)&(player->control));
	if (*control & PLAYER_MARKER)
		player_marker_remover(key, control);
	else if (key == LEFT_KEY)
		*control = (*control ^ LEFT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RIGHT_KEY || key == E_KEY)
		*control = (*control ^ RIGHT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RSFT_KEY)
		*control = (*control ^ FIRE_KEYPRESS) ^ FIRE_MAKER;
	else if (key == F_KEY)
		*control = (*control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
	else if (key == LSFT_KEY)
		*control = (*control ^ BONUS_SPEEDUP_KEYPRESS) ^ SPEED_MARKER;
	return(control == NOEVENTMASK ? true : false);
}

int			cube3d_key_press_manager(int key, void *param)//merge this funct with key loader
{
	t_player		*player;

	player = (t_player*)(((void**)param)[1]);
	player->control = NOEVENTMASK; //keep novent mask here ?
	key_loader(key, player, &(player->control), param);
	return(player->control != NOEVENTMASK ? true : false);
}

void		update_player(void *param)
{
    t_game_engine	*engine;
	t_player		*hero;
	int32_t			*control;
    int 			i;

	engine = (t_game_engine*)(((void**)param)[2]);
	hero = (t_player*)(((void**)param)[1]);
	control = (int32_t*)&engine->player->control;
    i = -1;
	if (hero->hp > 0)
	{
		hero->movement = create_vector2(hero->forward.x - hero->pos.x,
				hero->forward.y - hero->pos.y);
		hero->last_movement = create_vector2(hero->movement.x * cos(PI / 2) -
			hero->movement.y * sin(PI / 2), hero->movement.x * sin(PI / 2) +
			hero->movement.y * cos(PI / 2));
        while (g_cube3d_key_handler[++i].marker_control != NOCONTRL)
		    if (*control & g_cube3d_key_handler[i].marker_control)
		    	g_cube3d_key_handler[i].controler(*control, param);
		hero->hp = (hero->hp > 100) ? 100 : hero->hp;
	}
}

int			update(void *param)
{
	t_game_engine	*engine;
	t_player		*hero;
	t_map			*map;

	engine = (t_game_engine*)(((void**)param)[2]);
	hero = (t_player*)(((void**)param)[1]);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	map = (t_map*)(((void**)param)[0]);
	update_player(param);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	clear_screen();
	if (engine->bonus == true)//for the multi_thread bonus
		draw_wall_multi_thread(*hero, map);
	else if (engine->bonus == false)
		draw_wall(*hero, map);//any probs with x/y axes ?
	draw_gun(*map, hero);//check width and height issues
	draw_hud(*map);
	draw_health_bar(*map, *hero);
	draw_2d_map(map, hero);
	if (hero->hp <= 0)
		draw_game_over(*map);
	render_application();
	return (0);
}
