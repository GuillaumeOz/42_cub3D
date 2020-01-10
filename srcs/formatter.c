/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:39:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/10 19:36:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	free_buff(char ***to_free, t_data *data, int index, int mode)
{
	int i;

	i = -1;
	while (++i < index)
	{
		free((*to_free)[i]);
		free((*to_free));
	}
	free_config(data);
	if (mode == 0)
		catch_error("Malloc_formatter error 1");
	else
		catch_error("Malloc_formatter error 2");
}

map_checker()
{
	
}

static void	id_selector(t_config *data, char *file, int index)
{
	if (*(file + index)  == 'R')
		parse_resolution(&(data->resolution_size));
	else if (*(file + index) == 'N' && *(file + index + 1) == 'O')
		parse_texture(&(data->north_texture));
	else if (*(file + index) == 'S' && *(file + index + 1) == 'O')
		parse_texture(&(data->south_texture));
	else if (*(file + index) == 'W' && *(file + index + 1) == 'E')
		parse_texture(&(data->west_texture));
	else if (*(file + index) == 'E' && *(file + index + 1) == 'A')
		parse_texture(&(data->east_texture));
	else if (*(file + index) == 'S')
		parse_texture(&(data->sprite_texture));
	else if (*(file + index) == 'F')
		parse_env(&(data->floor));
	else if (*(file + index) == 'C')
		parse_env(&(data->ceiling));
}

static	int	check_file(t_config *data, char **file, int index)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < index)
	{
		while (file[i][++j])
			id_selector(data, file[i], j);
		j = -1;
		//add map checking and parsing 1  1     1
	}
	return (SUCCESS);
}

t_config	*formatter(char *title)
{
	t_config	*data;
	char		**file;
	int			fd;
	int			ret;
	int			i;

	data = malloc_config();
	data->title = ft_strdupfree(title, 1);
	fd = open("../map.cub", O_RDONLY);
	file = NULL;
	while (ret != 0)
	{
		file[i] = (char*)malloc(sizeof(char));
		if (file[i] == NULL)
			free_buff(&file, data, i, 0);
		ret = get_next_line(fd, &(file[i]));
		if (ret == -1)
			free_buff(&file, data, i, 0);
		i++;
	}
	(check_file(data, file, i)) == SUCCESS ?
		data = parse_map(data, file, i) : free_buff(&file, data, i, 1);
	data = parse_parameters(data, file, i);
	return (data);
}
