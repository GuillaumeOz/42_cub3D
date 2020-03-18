/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/11 20:02:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;

	size_t i;

	i = 0;

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argv[1], &resolution);
	resize_application((int)resolution.x, (int)resolution.y);

	while (i < engine.map_content->size)
	{
		PRINTS((char*)list_at(engine.map_content, i++));
	}
	// printf("(%f,%f)\n", engine.player->pos.x, engine.player->pos.y);

	add_interaction_to_application(&cube3d_key_manager, KEYPRESS, &engine);
	// add_interaction_to_application(&, KEYRELEASE, &engine);
	render_funct_application(&draw_map, &engine);

	return (run_application());
}
