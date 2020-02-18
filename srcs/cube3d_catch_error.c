/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_catch_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:06:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/18 17:32:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_error	g_cube3d_catch_error[] =
{
	{ MAIN_1, "Error\n Wrong number of arguments" },
	{ CREATE_GAME_ENGINE_1, "Error\n Can't malloc a t_game_engine" },
	{ CREATE_GAME_ENGINE_2, "Error\n Can't malloc a t_image" },
	{ CREATE_TILE_1, "Error\n Can't malloc a t_image in tile" },
	{ CREATE_TILE_2, "Error\n Can't malloc a t_tile" },
	{ SET_COLOR_TYPE_1, "Error\n Color for ceiling or floor already done" },
	{ SET_COLOR_TYPE_2, "Error\n Bad number of arguments for a color" },
	{ SET_COLOR_TYPE_3, "Error\n Arguments invalid for a color" },
	{ PARSE_GAME_ENGINE_1, "Error\n Arguments invalid for a color" },
	{ PARSE_RESOLUTION_1, "Error\n Bad number of arguments for resolution" },
	{ PARSE_RESOLUTION_2, "Error\n Arguments invalid for resolution" },

	{ CHECK_MAPNAME_1, "Error\n The file name is invalid" },
	{ CUBE_FORMATTER_1, "Error\n Data can't be allocated" },
	{ CUBE_FORMATTER_2, "Error\n Error with GNL return" },
	{ PARSE_TEXTURE_1, "Error\n Texture path is incorrect" },
	{ PARSE_RESOLUTION_1, "Error\n Resolution line is invalid" },
	{ PARSE_ENVIRONMENT_1, "Error\n Environment line is invalid" },
	{ CUBE_MAP_FORMATTER_1, "Error\n The map can't be malloc" },
	{ CUBE_MAP_FORMATTER_2, "Error\n Error with GNL return" },
	{ CUBE_MAP_FORMATTER_3, "Error\n The last line of the file is invalid" },
	{ CUBE_MAP_REALLOC_1, "Error\n The realloc array of map failed" },
	{ CUBE_MAP_REALLOC_2, "Error\n The realloc line of map failed" },
	{ CUBE_MAP_PARSE_1, "Error\n The first char of the line is not '1'" },
	{ CUBE_MAP_PARSE_2, "Error\n Forbidden char detected" },
	{ CUBE_MAP_PARSE_3, "Error\n The allocation of formatted line failed" },
	{ CUBE_MAP_PARSE_4, "Error\n The last char of the line is not '1'" },
	{ FILL_PLAYER_1, "Error\n There are to much player on the map" },
	{ CHECK_BORDER_PLAYER_1, "Error\n There are no player on the map" },
	{ CHECK_BORDER_PLAYER_2, "Error\n There are an error with map borders" },

	{ ERROR_NOT_FOUND, "The Error has not be catched... Good luck"}
};

void catch_error(int error_msg)
{
	int i;

	i = -1;
	while (g_cube3d_catch_error[++i].error_list != ERROR_NOT_FOUND)
	{
		if (error_msg == g_cube3d_catch_error[i].error_list)
		{
			ft_printf("%s\n", g_cube3d_catch_error[i].warning_msg);
			exit(FAILURE);
		}
	}
	if (g_cube3d_catch_error[i].error_list == ERROR_NOT_FOUND)
		ft_printf("\n%s\n", g_cube3d_catch_error[i].warning_msg);
	exit(FAILURE);
}
