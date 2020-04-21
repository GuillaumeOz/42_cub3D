/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/21 19:51:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
	t_game_engine	engine;
	t_vector2		resolution;

	if (argc < 2 || argc >= 4)//do the resolution rezize
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argc, argv, &resolution);
	resize_application((int)resolution.x, (int)resolution.y);
	do_save(&engine);
	add_interaction_to_application(&cube3d_key_released_manager, KEYRELEASE, KEYRELEASE, &engine);
	add_interaction_to_application(&cube3d_key_press_manager, KEYPRESS, KEYPRESSMASK, &engine);
	application_add_exit_control(DESTROYNOTIFY, &quit);
	render_funct_application(&draw_map, &engine);

	return (run_application());
}
