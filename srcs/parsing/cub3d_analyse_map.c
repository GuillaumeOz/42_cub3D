/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_analyse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:17:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:23:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	square_map(t_engine *engine, size_t size_x)
{
	t_list	*map;
	char	*line;
	char	*tmp;
	size_t	size;
	size_t	i;

	map = malloc_list(50);
	i = 0;
	while (i < engine->map->size)
	{
		line = (char *)list_at(engine->map, i);
		size = ft_strlen(line);
		tmp = (char *)ft_memalloc(size_x + 1);
		ft_strcpy(tmp, line);
		while (size < size_x)
			tmp[size++] = ' ';
		list_push_back(map, tmp);
		i++;
	}
	free_list(engine->map, &free);
	engine->map = map;
}

static	bool	check_x(t_list *map, size_t x, size_t y)
{
	char	*valid;
	char	*line;
	size_t	tmp_x;

	valid = "012NSEWabcdefghijk";
	line = (char *)list_at(map, y);
	tmp_x = x;
	while (line[tmp_x] != '1')
		line = (char *)list_at(map, --y);
	if ((ft_ischar(valid, line[tmp_x - 1]) == false)
		|| (ft_ischar(valid, line[tmp_x + 1]) == false))
		return (true);
	line = (char *)list_at(map, ++y);
	while (line[tmp_x] != '1')
		line = (char *)list_at(map, ++y);
	if ((ft_ischar(valid, line[tmp_x - 1]) == false)
		|| (ft_ischar(valid, line[tmp_x + 1]) == false))
		return (true);
	return (false);
}

static	bool	check_plus(t_list *map,
	t_int_vector2 map_size, int x, int y)
{
	char	*line;
	size_t	tmp_x;

	line = (char *)list_at(map, y);
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
		line = (char *)list_at(map, --y);
	}
	line = (char *)list_at(map, ++y);
	while (line[tmp_x] != '1')
	{
		if (y == (map_size.y - 1) || line[tmp_x] == ' ')
			return (true);
		line = (char *)list_at(map, ++y);
	}
	return (false);
}

static	void	check_borders(t_engine *engine, int size_x, int size_y)
{
	t_int_vector2	map_size;
	char			*charset;
	char			*line;
	int				x;
	int				y;

	y = 0;
	map_size = create_int_vector2(size_x, size_y);
	charset = "02NSEWabcdefghijk";
	while (y < size_y)
	{
		x = 0;
		line = (char *)list_at(engine->map, y);
		while (x < size_x)
		{
			if (ft_ischar(charset, line[x]) == true)
				if (y == 0 || x == 0
					|| check_plus(engine->map, map_size, x, y) == true
					|| check_x(engine->map, x, y) == true)
					cub3d_error(ERROR_PARSING30, "The map is invalid");
			x++;
		}
		y++;
	}
}

void	analyse_map(t_engine *engine, int size_x, int size_y)
{
	square_map(engine, size_x);
	check_borders(engine, size_x, size_y);
	load_map_informations(engine, size_x, size_y);
}
