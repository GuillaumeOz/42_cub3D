/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 15:44:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				quit(void *param)
{
	t_game_engine *engine;

	engine = (t_game_engine*)(((void**)param)[2]);
	free_game_engine(engine);
	close_application();
	return (0);
}

static void		do_save(void *param)
{
	t_game_engine *engine;

	engine = (t_game_engine*)(((void**)param)[2]);
	if (engine->save == true)
	{
		if (save_bmp(engine, engine->map, engine->player) == FAILURE)
			catch_error(DO_SAVE_1);
		ft_putstr("A photo was taken");
		quit(param);
	}
}

int				main(int argc, char **argv)
{
	void			*param[3];
	t_game_engine	*engine;
	t_vector2		resolution;

	if (argc < 2 || argc >= 4)
		catch_error(MAIN_1);
	XInitThreads();
	start_application(600, 600, "Cub3D (c)");
	engine = malloc_game_engine();
	cub3d_parsing(engine, argc, argv, &resolution);
	resize_application((int)resolution.x, (int)resolution.y);
	param[0] = engine->map;
	param[1] = engine->player;
	param[2] = engine;
	do_save(param);
	add_interaction_to_application(&cube3d_key_release_manager, KEYRELEASE, KEYRELEASEMASK, param);
	add_interaction_to_application(&cube3d_key_press_manager, KEYPRESS, KEYPRESSMASK, param);
	add_interaction_exit_control(&quit, DESTROYNOTIFY, param);
	application_update(&update, param);
	return (run_application());
}
