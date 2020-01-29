/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:06:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/29 20:09:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_error	g_cube3d_catch_error[] =
{
	{ "Main error 1", "Wrong number of arguments" },
	{ "Main error 2", "The file descriptor is incorrect" },
	{ "Cube_formatter error 1", "Data can't be allocated" },
	{ "Cube_formatter error 2", "Realloc error" },
	{ "Cube_formatter error 3", "File descriptor error (-1)" },
	{ "Malloc_formatter error 2", "The map is invalid" },
	{ "Malloc_parser error 1", "The texture path can't be malloc" },
	{ "Malloc_parser error 2", "The texture path can't be malloc" },
	{ "Map_checker error 1", "The map first line is invalid" },
	{ "Map_checker error 2", "The map content char is invalid" },
	{ "Map_checker error 3", "The map last line is invalid" },
	{ "Map_formatter error 1", "The number of lines can't be allocated" },
	{ "Check_player error 1", "There are too much player in the map" },
	{ "Check_player error 2", "There are no player on the map" },
	{ "Check_map error 1", "The map doesn't start with '1'" },
	{ "Check_map error 2", "The line is too big" },
	{ "Check_map error 3", "The map doesn't end with '1'" },
	{ "Check_border error 1", "The map doesn't end with '1'" },
	{ NULL, "The Error has not be catched... Good luck"}
};

void catch_error(char *error_msg)
{
	int i;
	int ret_msg;

	i = -1;
	debug
	while (g_cube3d_catch_error[++i].error_list)
	{
		ret_msg = ft_strcmp(g_cube3d_catch_error[i].error_list, error_msg);
		if (ret_msg == 0)
		{
			ft_printf("\n%s : %s\n", g_cube3d_catch_error[i].error_list, 
				g_cube3d_catch_error[i].warning_msg);
			exit(FAILURE);
		}
	}
	if (g_cube3d_catch_error[i].error_list == NULL)
		ft_printf("\n%s\n", g_cube3d_catch_error[i].warning_msg);
	exit(FAILURE);
}
