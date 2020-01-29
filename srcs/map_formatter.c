/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_formatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:41:05 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/29 18:46:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static size_t	strlen_without_char(char *line, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if(line[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void		check_border(char **map, int lineindex)
{
	size_t	currentline;
	size_t	nextline;
	int 	i;

	i = -1;
	while (++i < lineindex)
	{
		currentline = ft_strlen(map[i]);
		nextline = ft_strlen(map[i + 1]);
		if (currentline < nextline)
			while (currentline < nextline)
				if (map[i + 1][currentline++] != '1')
					catch_error("Check_border error 1");
		if (currentline > nextline)
			while (currentline > nextline)
					if (map[i][nextline++] != '1')
						catch_error("Check_border error 1");
	}
}

static void		check_parse_map(t_config *data, char **file, int lineindex, int i)
{
	size_t	malloc_size;
	int		j;
	int		k;
	int		h;

	malloc_size = 0;
	k = -1;
	while (i < lineindex)
	{
		j = -1;
		h = -1;
		if (file[i][0] != '1')
			catch_error("Check_map error 1");
		malloc_size = strlen_without_char(file[i], ' ');
		data->map[++k] = (char*)ft_memalloc(malloc_size + SENTINAL);
		if (data->map[k] == NULL)
			catch_error("Check_map error 2");
		while (file[i][++j])
			if(file[i][j] != ' ')
				data->map[k][++h] = file[i][j];
		if (file[i][j - 1] != '1')
			catch_error("Check_map error 3");
		i++;
	}
}

static void		check_player(t_config *data, char **file, int lineindex, int i)
{
	int j;

	j = -1;
	while (i < lineindex)
	{
		while (file[i][++j])
			if (file[i][j] == 'N' || file[i][j] == 'S' || file[i][j] == 'E'
				|| file[i][j] == 'W')
			{
				if (data->player_stance == 0)
					data->player_stance = file[i][j];
				else
					catch_error("Check_player error 1");
			}
		j = -1;
		i++;
	}
	if (data->player_stance == 0)
		catch_error("Check_player error 2");
}

void			map_formatter(t_config *data, char **file, int lineindex, int i)
{
	int currentline;

	currentline = (lineindex - i);
	data->map = (char**)ft_memalloc(currentline + SENTINAL);
	if (data->map == NULL)
		catch_error("Map_formatter error 1");
	check_player(data, file, lineindex, i);
	check_parse_map(data, file, lineindex, i);
	check_border(data->map, (currentline + SENTINAL));
}
