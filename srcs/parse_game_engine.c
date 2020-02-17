/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:38:57 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/17 20:04:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution)
{
	size_t i;
	size_t j;
	char *descriptor;
	char *content;

	i = 0;
	content = NULL;
	while (is_engine_full(engine) == false && get_next_line(fd, &content) > 0)
	{
		descriptor = ft_strcut(&content, ' ');
		j = 0;
		while (content[j] == ' ')
			j++;
		if (parse_environement_texture(engine, descriptor, &(content[j])) == true)
			;
		else if (parse_environement_color(engine, descriptor, &(content[j])) == true)
			;
		else if (parse_resolution(descriptor, &(content[j]), resolution) == true)
			;
		else if (ft_strlen(descriptor) == 0)
			;
		else
			error_exit(1, ft_eprintf("Error on line %d in the file", i));
		i++;
	}
	engine->wall_tile = malloc_tile(wall, *(engine->ceiling), *(engine->floor));
	set_tile_texture(engine->wall_tile, north, engine->texture[0]);
	set_tile_texture(engine->wall_tile, east, engine->texture[1]);// create a new function for fill up this part
	set_tile_texture(engine->wall_tile, south, engine->texture[2]);
	set_tile_texture(engine->wall_tile, west, engine->texture[3]);
	engine->empty_tile = malloc_tile(empty, *(engine->ceiling), *(engine->floor));
}
