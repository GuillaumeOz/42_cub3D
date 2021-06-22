/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:58:35 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:31:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_the_map(char **line, int *ret, int fd)
{
	*ret = 1;
	while (*ret > 0)
	{
		*ret = get_next_line(fd, line);
		if (ft_strlen(*line) != 0)
			break ;
		else
			free(*line);
	}
	if (*ret == 0)
		cub3d_error(ERROR_PARSING27, "The map is missing");
}

static	bool	check_map_line_format(t_engine *engine, char *line,
	size_t *map_size_x, size_t *map_size_y)
{
	char	*content;

	content = ft_strdup(line);
	if (*map_size_x == 0)
		*map_size_x = ft_strlen(content);
	if (ft_strlen(content) > *map_size_x)
		*map_size_x = ft_strlen(content);
	list_push_back(engine->map, content);
	(*map_size_y) += 1;
	if (ft_isonlycharset(line, engine->allow_charset) == false)
		return (false);
	return (true);
}

void	parse_map(t_engine *engine, int fd)
{
	size_t	map_size_x;
	size_t	map_size_y;
	char	*line;
	int		ret;

	map_size_x = 0;
	map_size_y = 0;
	find_the_map(&line, &ret, fd);
	if (check_map_line_format(engine, line, &map_size_x, &map_size_y) == false)
		cub3d_error(ERROR_PARSING28, "Forbidden char detected in the map");
	free(line);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
			cub3d_error(ERROR_PARSING29, "Empty line in the map part");
		else if (check_map_line_format(engine, line,
				&map_size_x, &map_size_y) == false)
			cub3d_error(ERROR_PARSING28, "Forbidden char detected in the map");
		free(line);
	}
	analyse_map(engine, map_size_x, map_size_y);
}
