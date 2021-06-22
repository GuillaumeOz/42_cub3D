/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_load_map_informations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:27:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 19:15:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	last_check(t_engine *engine)
{
	if (engine->player == NULL)
		cub3d_error(ERROR_PARSING33, "There are no player on map");
}

void	load_map_informations(t_engine *engine, int size_x, int size_y)
{
	char	*line;
	int		x;
	int		y;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		line = list_at(engine->map, y);
		while (x < size_x)
		{
			if (line[x] == '2')
				load_sprite_basic(engine, BASIC, x, y);
			else if (ft_ischar("abcdefghijk", line[x]) == true)
				load_secret_door_bonus(engine);
			else if (line[x] == 'N' || line[x] == 'S'
				|| line[x] == 'E' || line[x] == 'W')
				load_player(engine, line[x], x, y);
			x++;
		}
		y++;
	}
	last_check(engine);
}
