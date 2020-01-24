/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:06:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/24 12:43:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_error	g_cube3d_catch_error[] =
{
	{ "Malloc_map error 1", "The map is too small" },
	{ "Malloc_map error 2", "The map is too small" },
	{ "Malloc_formatter error 1", "Output file allocation failed" },
	{ "Malloc_formatter error 2", "The map is invalid" },
	{ "Malloc_parser error 1", "The texture path can't be malloc" },
	{ "Malloc_parser error 2", "The texture path can't be malloc" },
	{ NULL, "The Error has not be catched... Good luck"}
};

void catch_error(char *error_msg)
{
	int i;
	int ret_msg;

	i = -1;
	while (g_cube3d_catch_error[++i].error_list)
	{
		ret_msg = ft_strcmp(g_cube3d_catch_error[i].error_list, error_msg);
		if (ret_msg == 0)
		{
			ft_printf("\n%s : %s\n", g_cube3d_catch_error[i].error_list, 
				g_cube3d_catch_error[i].warning_msg);
			exit(EXIT_FAILURE);
		}
	}
	if (g_cube3d_catch_error[i].error_list == NULL)
		ft_printf("\n%s\n", g_cube3d_catch_error[i].warning_msg);
	exit(EXIT_FAILURE);
}
