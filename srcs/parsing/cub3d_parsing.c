/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:16:22 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 15:45:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_engine *engine, int argc, char **argv)
{
	int	fd;

	check_arguments(engine, argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		cub3d_error(ERROR_PARSING5, "The .cub file cannot be opened");
	parse_engine(engine, fd);
	parse_map(engine, fd);
	close(fd);
}
