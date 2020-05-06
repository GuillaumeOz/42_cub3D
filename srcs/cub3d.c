/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/06 14:10:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		quit(void)
{
	exit(0);
	return (0);
}

static void		do_save(t_game_engine *engine)
{
	if (engine->save == true)
	{
		if (save_bmp(engine, engine->map, engine->player) == FAILURE)
			catch_error(DO_SAVE_1);
		ft_putstr("A photo was taken");
		exit(SUCCESS);
	}
}

int main(int argc, char **argv)
{
	void			*param[3];
	t_game_engine	*engine;
	t_vector2		resolution;

	if (argc < 2 || argc >= 4)
		catch_error(MAIN_1);
	XInitThreads();
	start_application(600, 600, "Cub3D (c)");
	engine = malloc_game_engine();
	cube3d_parsing(engine, argc, argv, &resolution);
	resize_application((int)resolution.x, (int)resolution.y);
	do_save(engine);
	param[0] = engine->map;
	param[1] = engine->player;
	param[2] = engine;
	add_interaction_to_application(&cube3d_key_release_manager, KEYRELEASE, KEYRELEASEMASK, param);
	add_interaction_to_application(&cube3d_key_press_manager, KEYPRESS, KEYPRESSMASK, param);
	add_interaction_exit_control(&quit, DESTROYNOTIFY);
	application_update(&update, param);
	return (run_application());
}

//change the name into "cub3D"
//create two part: with bonus multi-thread and another without