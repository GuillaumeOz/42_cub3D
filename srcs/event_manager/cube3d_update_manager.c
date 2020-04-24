/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_update_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:22:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 19:42:24 by gozsertt         ###   ########.fr       */
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

void		update_player(void *param)
{
    t_game_engine	*engine;
	t_player		*hero;
	int32_t			*control;
    int i;

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
