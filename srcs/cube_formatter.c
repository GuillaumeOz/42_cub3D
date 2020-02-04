/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:39:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/04 20:13:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void check_mapname(char *map_name)
{
	int i;

	i = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	if (map_name[i] == '\0')
		catch_error(CHECK_MAPNAME_1);
	if (map_name[i] == '.')
		if ((ft_strcmp(map_name + i, ".cub")) != 0)
			catch_error(CHECK_MAPNAME_1);
}

static void	id_selector(t_config *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			parse_resolution(data->resolution_size, line + i);
		else if (line[i] == 'N' && line[i + 1] == 'O')
			parse_texture(&(data->north_texture), line + i);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			parse_texture(&(data->south_texture), line + i);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			parse_texture(&(data->west_texture), line + i);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			parse_texture(&(data->east_texture), line + i);
		else if (line[i] == 'S')
			parse_texture(&(data->sprite_texture), line + i);
		else if (line[i] == 'F')
			parse_environment(data->floor, line + i);
		else if (line[i] == 'C')
			parse_environment(data->ceiling, line + i);
		i++;
	}
}

static void cube_map_realloc(t_config *data, int nbline)
{
	char **ret;
	int i;

	i = -1;
	nbline += 1;
	ret = (char**)malloc(sizeof(char*) * (nbline + SENTINAL));
	if (ret == NULL)
		catch_error(CUBE_MAP_REALLOC_1);
	ret[nbline] = NULL;
	while (data->map[++i] != NULL)
	{
		ret[i] = ft_strdupfree(data->map[i], 1);
		if (ret[i] == NULL)
			catch_error(CUBE_MAP_REALLOC_2);
	}
	free(data->map);
	data->map = ret;
}

static void cube_map_formatter(t_config *data, char *line, int fd)
{
	int ret;
	int i;

	i = 0;
	data->map = (char**)malloc(sizeof(char*) * (3 + SENTINAL));
	if (data->map == NULL)
		catch_error(CUBE_MAP_FORMATTER_1);
	data->map[i] = cube_map_parse(data, line, i);
	data->map[3] = NULL;
	i++;
	free(line);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1 || line == NULL)
 			catch_error(CUBE_MAP_FORMATTER_2);
		data->map[i] = cube_map_parse(data, line, i);
		if (data->map[i + SENTINAL] == NULL)
			cube_map_realloc(data, (i + SENTINAL));
		i++;
	}
	(ft_isonlycharset(line, " 1")) == SUCCESS ?
		data->map[i] = cube_map_parse(data, line, i) :
		catch_error(CUBE_MAP_FORMATTER_3);
	free(line);
}

t_config	*cube_formatter(char *title, char *map_name)
{
	t_config	*data;
	char		*line;
	int			ret;
	int			fd;

	data = malloc_config();
	if (data == NULL)
		catch_error(CUBE_FORMATTER_1);
	check_mapname(map_name);
	fd = open(map_name, O_RDONLY);
	data->title = ft_strdup(title);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1 || line == NULL)
 			catch_error(CUBE_FORMATTER_2);
		id_selector(data, line);
		if ((ft_isonlycharset(line, " 1")) == SUCCESS)
		{
			cube_map_formatter(data, line, fd);
			break ;
		}
		free(line);
	}
	check_border_player(data);
	return (data);
}
