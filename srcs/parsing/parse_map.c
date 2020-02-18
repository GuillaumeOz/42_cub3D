/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:57:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/18 14:53:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool parse_map_line(t_game_engine *engine, char *line, t_vector2 *map_size)
{
	char *content;

	content = ft_strdup_no_c(line, ' ');
	if (map_size->x == 0)
		map_size->x = ft_strlen(content);
	if (ft_strlen(content) != map_size->x)
		return (false);
	list_push_back(engine->map_content, content);
	map_size->y++;
	return (true);
}

void compute_map(t_game_engine *engine, t_vector2 map_size)
{
	engine->map = malloc_map(engine, map_size, engine->map_content);
}

void parse_map(t_game_engine *engine, int fd)
{
	t_vector2 map_size;
	int		i;
	bool	found;
	char	*line;

	line = NULL;
	found = false;
	map_size = create_vector2(0, 0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 0 && found == false)
			;
		else if (ft_strlen(line) != 0)
		{
			if (parse_map_line(engine, line, &map_size) == true)
				found = true;
			else
				error_exit(1, ft_eprintf("Error on line %d in the file", i));
		}
		else
			error_exit(1, ft_eprintf("Error on line %d in the file", i));
		i++;
	}
	compute_map(engine, map_size);
}
