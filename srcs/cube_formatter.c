/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:39:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/31 21:55:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

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

	i = -1;
	data->map = (char**)malloc(sizeof(char*) * (3 + SENTINAL));
	if (data->map == NULL)
		catch_error(CUBE_MAP_FORMATTER_1);
	data->map[++i] = cube_map_parse(line);
	data->map[3] = NULL;
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1)
 			catch_error(CUBE_MAP_FORMATTER_2);
		if (line == NULL)
			catch_error(CUBE_MAP_FORMATTER_3);
		data->map[++i] = cube_map_parse(line);
		//PRINTS(line);
		if (data->map[i + SENTINAL] == NULL)
			cube_map_realloc(data, (i + SENTINAL));
	}
	(ft_isonlycharset(line, " 1")) == SUCCESS ?
		data->map[++i] = cube_map_parse(line) :
		catch_error(CUBE_MAP_FORMATTER_4);
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
		if (ret == -1)
 			catch_error(CUBE_FORMATTER_2);
		if (line == NULL)
			catch_error(CUBE_FORMATTER_3);
		id_selector(data, line);
		if ((ft_isonlycharset(line, " 1")) == SUCCESS)
		{
			cube_map_formatter(data, line, fd);
			break ;
		}
		free(line);
	}
	//check_line_border();
	exit(FAILURE);
	return (data);
	// printf("title -> %s\n", data->title);
	// printf("reso x -> %d\n", (int)data->resolution_size->x);
	// printf("reso y -> %d\n", (int)data->resolution_size->y);
	// printf("north -> %s\n", data->north_texture);
	// printf("south -> %s\n", data->south_texture);
	// printf("west -> %s\n", data->west_texture);
	// printf("east -> %s\n", data->east_texture);
	// printf("sprite -> %s\n", data->sprite_texture);
	// printf("floor R -> %hhu\n", data->floor->r);
	// printf("floor G -> %hhu\n", data->floor->g);
	// printf("floor B -> %hhu\n", data->floor->b);
	// printf("ceiling R -> %hhu\n", data->ceiling->r);
	// printf("ceiling G -> %hhu\n", data->ceiling->g);
	// printf("ceiling B -> %hhu\n", data->ceiling->b);
	// exit(FAILURE);
	// if ((check_line(&data, line, i)) == SUCCESS)
	// 	free_buff(&line, i);
}
