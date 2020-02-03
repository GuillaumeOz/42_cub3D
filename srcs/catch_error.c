/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:06:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/03 11:52:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_error	g_cube3d_catch_error[] =
{
	{ MAIN_1, "Error\n Wrong number of arguments" },
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

	// { "Cube_formatter error 1", "Data can't be allocated" },
	// { "Cube_formatter error 2", "Realloc error" },
	// { "Cube_formatter error 3", "File descriptor error (-1)" },
	// { "Malloc_formatter error 2", "The map is invalid" },
	// { "Malloc_parser error 1", "The texture path can't be malloc" },
	// { "Malloc_parser error 2", "The texture path can't be malloc" },
	// { "Map_checker error 1", "The map first line is invalid" },
	// { "Map_checker error 2", "The map content char is invalid" },
	// { "Map_checker error 3", "The map last line is invalid" },
	// { "Map_formatter error 1", "The number of lines can't be allocated" },
	// { "Check_player error 1", "There are too much player in the map" },
	// { "Check_player error 2", "There are no player on the map" },
	// { "Check_map error 1", "The map doesn't start with '1'" },
	// { "Check_map error 2", "The line is too big" },
	// { "Check_map error 3", "The map doesn't end with '1'" },
	// { "Check_border error 1", "The map doesn't end with '1'" },
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
