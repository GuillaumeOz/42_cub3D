/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/21 17:54:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;

	size_t				i;

	i = -1;

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argv[1], &resolution);

	// printf("Resolution (%f,%f)\n", resolution.x, resolution.y);
	PRINTV(resolution);
	printf("Ceiling (%u,%u,%u,%u)\n", engine.ceiling->r, engine.ceiling->g, engine.ceiling->b, engine.ceiling->a);
	printf("Floor (%u,%u,%u,%u)\n", engine.ceiling->r, engine.ceiling->g, engine.ceiling->b, engine.ceiling->a);

	while (++i < engine.map_content->size)
	{
		PRINTS(*(list_get(engine.map_content, i)));
	}

	// PRINTS(*(list_get(engine.map_content, i)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTS(*(list_get(engine.map_content, 0)));
	// PRINTF();
	// PRINTF();
	// PRINTF();
	// PRINTF();
	// PRINTF();
	// PRINTF();
	// PRINTF();
	// PRINTF();
	// PRINTF();

	return (0);
}
