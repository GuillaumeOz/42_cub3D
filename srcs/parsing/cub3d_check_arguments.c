/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:33:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 15:45:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_file_name(char *file_name)
{
	size_t	i;

	i = ft_strlen(file_name);
	if (i < 5)
		cub3d_error(ERROR_PARSING3, "The file name is incorrect");
	if (file_name[i - 1] != 'b'
		|| file_name[i - 2] != 'u'
		|| file_name[i - 3] != 'c'
		|| file_name[i - 4] != '.')
		cub3d_error(ERROR_PARSING4, "The file name extension is incorrect");
}

static void	check_save_option(t_engine *engine, char **argv)
{
	bool	same;

	same = ft_strcmp(argv[2], "--save");
	if (same == true && BONUS == true)
		engine->bonus |= SAVE_BONUS;
	else
		cub3d_error(ERROR_PARSING2, "The arguments are incorrect");
}

void	check_arguments(t_engine *engine, int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		cub3d_error(ERROR_PARSING1, "The number of arguments is incorrect");
	if (argc == 3)
		check_save_option(engine, argv);
	check_file_name(argv[1]);
}
