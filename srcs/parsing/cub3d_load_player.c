/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_load_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:38:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:47:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_player(t_engine *engine, char dir, int x, int y)
{
	if (engine->player != NULL)
		cub3d_error(ERROR_PARSING31, "Many player detected on map");
	else
	{
		if (dir == 'N')
			engine->player = malloc_player(x + 0.5f, y + 0.5f, NORTH_DIR);
		else if (dir == 'S')
			engine->player = malloc_player(x + 0.5f, y + 0.5f, SOUTH_DIR);
		else if (dir == 'E')
			engine->player = malloc_player(x + 0.5f, y + 0.5f, EAST_DIR);
		else if (dir == 'W')
			engine->player = malloc_player(x + 0.5f, y + 0.5f, WEST_DIR);
	}
}
