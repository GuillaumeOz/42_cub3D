/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_event_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:18:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/02 21:42:57 by gozsertt         ###   ########.fr       */
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

static void player_marker_remover(int key, int32_t *control)
{
	if (key == W_KEY)
		*control = (*control ^ W_KEYPRESS) ^ PLAYER_MARKER ;
	else if (key == A_KEY)
		*control = (*control ^ A_KEYPRESS) ^ PLAYER_MARKER ;
	else if (key == S_KEY)
		*control = (*control ^ S_KEYPRESS) ^ PLAYER_MARKER ;
	else if (key == D_KEY)
		*control = (*control ^ D_KEYPRESS) ^ PLAYER_MARKER ;
}

int cube3d_key_release_manager(int key, void *param)
{
	t_player		*player;
	int32_t			*control;

	player = (t_player*)(((void**)param)[1]);
	control = (int32_t*)((int32_t*)&(player->control));
	if (key == LSFT_KEY)
	{
		*control = (*control ^ BONUS_SPEEDUP_KEYPRESS) ^ SPEED_MARKER;
		player->bonus_speed = 1.0f;
	}
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		player_marker_remover(key, control);
	else if (key == LEFT_KEY)
		*control = (*control ^ LEFT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		*control = (*control ^ RIGHT_KEYPRESS) ^ CAMERA_MARKER;
	else if (key == RSFT_KEY)
		*control = (*control ^ FIRE_KEYPRESS) ^ FIRE_MAKER;
	else if (key == R_KEY)
		*control = (*control ^ RESPAWN_KEYPRESS) ^ INTERACT_MAKER;
	// else if (key == F_KEY)
	// 	*control = (*control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
	return(control == NOEVENTMASK ? true : false);
}

static	void	player_marker_loader(int key, int32_t *control)
{
	if (key == W_KEY)
		*control = (*control | W_KEYPRESS) | PLAYER_MARKER;
	else if (key == A_KEY)
		*control = (*control | A_KEYPRESS) | PLAYER_MARKER;
	else if (key == S_KEY)
		*control = (*control | S_KEYPRESS) | PLAYER_MARKER;
	else if (key == D_KEY)
		*control = (*control | D_KEYPRESS) | PLAYER_MARKER;
}

int			cube3d_key_press_manager(int key, void *param)
{
	t_player		*player;
	int32_t			*control;

	player = (t_player*)(((void**)param)[1]);
	control = (int32_t*)((int32_t*)&(player->control));
	if (key == ESC_KEY)
		close_application();
	if (key == LSFT_KEY)
		*control = (*control | BONUS_SPEEDUP_KEYPRESS) | SPEED_MARKER;
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		player_marker_loader(key, control);
	else if (key == LEFT_KEY)
		*control = (*control | LEFT_KEYPRESS) | CAMERA_MARKER;
	else if (key == RIGHT_KEY)
		*control = (*control | RIGHT_KEYPRESS) | CAMERA_MARKER;
	else if ((key == Q_KEY || key == E_KEY) && player->hp > 0)
		player->hp += key == Q_KEY ? -10 : 10;
	else if ((key == RSFT_KEY) && player->hp > 0)
		*control = (*control | FIRE_KEYPRESS) | FIRE_MAKER;
	else if (key == B_KEY && player->hp >= 0)//RNT dont work
		*control = (*control | RESPAWN_KEYPRESS) | INTERACT_MAKER;
	else if (key == F_KEY && !(*control & INTERACT_MAKER))
		*control = (*control | INTERACT_KEYPRESS) | INTERACT_MAKER;
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

// static void test_put_pixel(t_image *image, t_vector2 pos, t_color color)
// {
// 	t_color actual;
// 	t_color tmp;
// 	int pixel_index;

// 	if (pos.x < 0 || pos.x >= image->size.x || pos.y < 0 ||
// 		pos.y >= image->size.y)
// 		return;
// 	pixel_index = convert_2di_1di(pos, g_app->size) * 4;
// 	actual = create_color(
// 		image->pixels[pixel_index + RED_COMP],
// 		image->pixels[pixel_index + GREEN_COMP],
// 		image->pixels[pixel_index + BLUE_COMP],
// 		255
// 	);
// 	tmp = fuze_color(actual, color);
// 	image->pixels[pixel_index + RED_COMP] = tmp.r;
// 	image->pixels[pixel_index + GREEN_COMP] = tmp.g;
// 	image->pixels[pixel_index + BLUE_COMP] = tmp.b;
// }

static void			test_set_pixel(t_vector2 pos, t_color color)
{
	int pixel_index;

	if (pos.x < 0 || pos.x >= g_app->size.x || pos.y < 0 ||
												pos.y >= g_app->size.y)
		return ;
	
	pixel_index = ((int)(pos.x) + ((int)(pos.y) * (int)(g_app->size.x))) * 4;
	g_app->image->pixels[pixel_index + RED_COMP] = color.r;
	g_app->image->pixels[pixel_index + GREEN_COMP] = color.g;
	g_app->image->pixels[pixel_index + BLUE_COMP] = color.b;
	g_app->image->pixels[pixel_index + ALPHA_COMP] = color.a;
}

static void	test_clear()
{
	t_vector2	pos;
	t_color		color;

	pos = create_vector2(0, 0);
	color = create_color(0, 0, 0, 255);
	// mlx_clear_window(g_app->mlx_ptr, g_app->win_ptr);
	while (pos.x < (size_t)g_app->size.x)
	{
		pos.y = 0;
		while (pos.y < (size_t)g_app->size.y)
		{
			test_set_pixel(pos, color);
			pos.y++;
		}
		pos.x++;
	}
}

// static void	test_clear1()
// {
// 	size_t i;
// 	size_t j;

// 	mlx_clear_window(g_app->mlx_ptr, g_app->win_ptr);
// 	i = 0;
// 	while (i < g_app->size.x)
// 	{
// 		j = 0;
// 		while (j < g_app->size.y)
// 		{
// 			test_put_pixel(g_app->image, create_vector2(i, j), create_color(0, 0, 0, 255));
// 			j++;
// 		}
// 		i++;
// 	}
// }

int			update(void *param)
{
	t_game_engine	*engine;//change WORLD_CHANGE_MARKER
	t_player		*hero;
	t_map			*map;

	// clear_screen();
	// mlx_clear_window(g_app->mlx_ptr, g_app->win_ptr);
	// clear_application(create_color(0, 0, 0, 0));
	// clear_application(create_color(0, 0, 0, 255));
	// mlx_clear_window(g_app->mlx_ptr, g_app->win_ptr);
	//clear_screen();// fix this funct "Black band bug"
	engine = (t_game_engine*)(((void**)param)[2]);
	hero = (t_player*)(((void**)param)[1]);
	map = (t_map*)(((void**)param)[0]);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));

	test_clear();

	update_player(param);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	if (engine->bonus == true)//Do a multithread option in .cub
		draw_wall_multi_thread(*hero, map);
	else if (engine->bonus == false)
		draw_wall(*hero, map);
	draw_gun(*map, hero);
	draw_hud(*map);
	draw_health_bar(*map, *hero);
	draw_2d_map(map, hero);
	if (hero->hp <= 0)
		draw_game_over(*map);
	render_application();
	return (0);
}
