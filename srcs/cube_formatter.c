/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:39:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/29 22:05:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

static void	free_buff(char ***to_free, int index)
{
	int i;

	i = -1;
	while (++i < index)
		free((*to_free)[i]);
	free((*to_free));
}

static	void	id_selector(t_config *data, char *file, int index)
{
	if (*(file + index)  == 'R')
		parse_resolution(&(data->resolution_size), file + index);
	else if (*(file + index) == 'N' && *(file + index + 1) == 'O')
		parse_texture(&(data->north_texture), file + index + 1);
	else if (*(file + index) == 'S' && *(file + index + 1) == 'O')
		parse_texture(&(data->south_texture), file + index + 1);
	else if (*(file + index) == 'W' && *(file + index + 1) == 'E')
		parse_texture(&(data->west_texture), file + index + 1);
	else if (*(file + index) == 'E' && *(file + index + 1) == 'A')
		parse_texture(&(data->east_texture), file + index + 1);
	else if (*(file + index) == 'S')
		parse_texture(&(data->sprite_texture), file + index);
	else if (*(file + index) == 'F')
		parse_environment(&(data->floor), file + index);
	else if (*(file + index) == 'C')
		parse_environment(&(data->ceiling), file + index);
}

static	int map_checker(t_config *data, char **file, int lineindex, int i)
{
	int tmp;

	tmp = i;
	if ((ft_isonlycharset(file[i], " 1")) == FAILURE)
		catch_error("Map_checker error 1");
	while (i++ < lineindex)
		if ((ft_isonlycharset(file[i], " 102NSEW")) == FAILURE)
			catch_error("Map_checker error 2");
	if ((ft_isonlycharset(file[i], " 1")) == FAILURE)
		catch_error("Map_checker error 3");
	i = tmp;
	map_formatter(data, file, lineindex, i);
	return (SUCCESS);
}

static	int	check_file(t_config **data, char **file, int index)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < index)
	{
		while (file[i][++j])
			id_selector((*data), file[i], j);
		j = -1;
		if ((ft_isonlycharset(file[i], " 1")) == SUCCESS)
			break ;
	}
	map_checker((*data), file, index, i);
	return (SUCCESS);
}

char		**cube_realloc(char **file, int size)
{
	char	**newfile;
	int		i;

	i = -1;
	if (file == NULL)
		newfile = (char**)malloc(sizeof(char*));
	else
	{
		if (!(newfile = (char**)malloc(sizeof(char*) * size)))
			return (NULL);
		while (++i < size)
			newfile[i] = file[i];
	}
	free_buff(&(file), size);
	if (newfile == NULL)
		return (NULL);
	return (newfile);
}

t_config	*cube_formatter(char *title, int fd)
{
	t_config	*data;
	char		**file;
	int			ret;
	int			i;

	data = malloc_config();
	if (data == NULL)
		catch_error("Formatter error 1");
	data->title = ft_strdup(title);
	ret = 1;
	i = 0;
	file = NULL;
	while (ret != 0)
	{
		if (!(file = cube_realloc(file, i)) || file == NULL)
			catch_error("Cube_formatter error 2");
		ret = get_next_line(fd, &(file[i]));
		if (ret == -1)
			catch_error("Cube_formatter error 3");
		i++;
		printf("%s\n", file[i]);
	}
	if ((check_file(&data, file, i)) == SUCCESS)
		free_buff(&file, i);
	return (data);
}
