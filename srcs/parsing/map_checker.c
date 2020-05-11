/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:17:22 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/10 15:00:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	diagonal_check(t_list *map, size_t y, size_t x)
{
	char	*valid;
	char	*line;
	size_t	tmp_x;

	valid = "H4M3012SNEW";
	line = (char*)list_at(map, y);
	tmp_x = x;
	while (line[tmp_x] != '1')
		line = (char*)list_at(map, --y);
	if ((ft_ischar(valid, line[tmp_x - 1]) == FAILURE) ||
	(ft_ischar(valid, line[tmp_x + 1]) == FAILURE))
		return (true);
	line = (char*)list_at(map, ++y);
	while (line[tmp_x] != '1')
		line = (char*)list_at(map, ++y);
	if ((ft_ischar(valid, line[tmp_x - 1]) == FAILURE) ||
	(ft_ischar(valid, line[tmp_x + 1]) == FAILURE))
		return (true);
	return (false);
}

bool	cross_check(t_list *map, t_vector2 map_size, size_t y, size_t x)
{
	char	*line;
	size_t	tmp_x;

	line = (char*)list_at(map, y);
	tmp_x = x;
	while (line[--x] != '1')
		if (x == 0 || line[x] == ' ')
			return (true);
	while (line[++x] != '1')
		if (x == (map_size.x - 1) || line[x] == ' ')
			return (true);
	while (line[tmp_x] != '1')
	{
		if (y == 0 || line[tmp_x] == ' ')
			return (true);
		line = (char*)list_at(map, --y);
	}
	line = (char*)list_at(map, ++y);
	while (line[tmp_x] != '1')
	{
		if (y == (map_size.y - 1) || line[tmp_x] == ' ')
			return (true);
		line = (char*)list_at(map, ++y);
	}
	return (false);
}
