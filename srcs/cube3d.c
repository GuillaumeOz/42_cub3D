/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/27 16:10:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
	start_application(600, 600, "Cube3D");
	engine = malloc_game_engine();
	cube3d_parsing(engine, argc, argv, &resolution);
	resize_application((int)resolution.x, (int)resolution.y);
	do_save(engine);
	param[0] = engine->map;
	param[1] = engine->player;
	param[2] = engine;
	//convert player position -> pixels to vector2

	//engine->player->control = (engine->player->control | LEFT_KEYPRESS) | CAMERA_MARKER;
	add_interaction_to_application(&cube3d_key_release_manager, KEYRELEASE, KEYRELEASEMASK, param);

	add_interaction_to_application(&cube3d_key_press_manager, KEYPRESS, KEYPRESSMASK, param);
	add_interaction_exit_control(&quit, DESTROYNOTIFY);//check if we need a maskevent
	application_update(&update, param);

	return (run_application());
}



	// size_t		i;
	// size_t 		j;

	// i = 0;
	// j = 0;

	// while (i < engine->map->size.y)
	// {
	// 	PRINTS((char*)list_at(engine->map_content, i))
	// 	j = 0;
	// 	while (j < engine->map->size.x)
	// 	{
	// 		if (engine->map->board[i][j]->type == empty)
	// 			ft_putstr("empty ");
	// 		if (engine->map->board[i][j]->type == wall)
	// 			ft_putstr("wall ");
	// 		if (engine->map->board[i][j]->type == sprite)
	// 			ft_putstr("sprite ");
	// 		if (engine->map->board[i][j]->type == door)
	// 			ft_putstr("door ");
	// 		if (engine->map->board[i][j]->type == closed_door)
	// 			ft_putstr("closed_door ");
	// 		if (engine->map->board[i][j]->type == level)
	// 			ft_putstr("level ");
	// 		if (engine->map->board[i][j]->type == medikit)
	// 			ft_putstr("medikit ");
	// 		if (engine->map->board[i][j]->type == monster)
	// 			ft_putstr("monster ");
	// 		if (engine->map->board[i][j]->type == dead_monster)
	// 			ft_putstr("dead_monster ");
	// 		j++;
	// 	}
	// 	PRINTS("\n")
	// 	i++;
	// }
	// exit(0);