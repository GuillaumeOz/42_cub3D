/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_catch_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:06:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/07 16:49:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_error	g_cube3d_catch_error[] =
{
	{ MAIN_1, "Error\nWrong number of arguments" },
	{ CHECK_SAVE_1, "Error\nSecond argument is wrong" },
	{ DO_SAVE_1, "Error\nError while saving the image"},
	{ CREATE_GAME_ENGINE_1, "Error\nCan't malloc a t_game_engine" },
	{ CREATE_GAME_ENGINE_2, "Error\nCan't malloc a t_image" },
	{ CREATE_TILE_1, "Error\nCan't malloc a t_image in tile" },
	{ CREATE_TILE_2, "Error\nCan't malloc a t_tile" },
	{ CHECK_MAPNAME_1, "Error\nThe file name is invalid" },
	{ SET_COLOR_TYPE_1, "Error\nColor for ceiling or floor already done" },
	{ SET_COLOR_TYPE_2, "Error\nBad number of arguments for a color" },
	{ SET_COLOR_TYPE_3, "Error\nArguments invalid for a color" },
	{ PARSE_GAME_ENGINE_1, "Error\nSome arguments are invalid" },
	{ PARSE_RESOLUTION_1, "Error\nBad number of arguments for resolution" },
	{ PARSE_RESOLUTION_2, "Error\nArguments invalid for resolution" },
	{ PARSE_RESOLUTION_3, "Error\nThe Resolution is incorrect" },
	{ PARSE_ENVIRONEMENT_COLOR_1, "Error\nA descriptor line is incorrect" },
	{ PARSE_ENVIRONEMENT_COLOR_2, "Error\nA descriptor line is incorrect" },
	{ MALLOC_MAP_1, "Error\n Can't malloc a t_map" },
	{ PARSE_MAP_1, "Error\n A line in the file is inccorect" },
	{ PARSE_MAP_2, "Error\nThe map part of the file is incorrect" },
	{ FLOOD_FILL_1, "Error\nForbidden char detected char on the map" },
	{ FLOOD_FILL_2, "Error\nThe map is invalid" },
	{ MALLOC_TILE_TAB_1, "Error\n Can't malloc a t_tile **" },
	{ MALLOC_TILE_TAB_2, "Error\n Can't malloc a t_tile *" },
	{ CREATE_MAP_1, "Multiple player on the map" },
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
		ft_printf("\n%s\n", g_cube3d_catch_error[i].warning_msg);//check ft_printf %v
	exit(FAILURE);
}
