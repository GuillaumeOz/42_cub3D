/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_map_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:12:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/05 17:38:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	int		ft_strlen_without(char *line, char c)
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

static	void	fill_proportionality(t_config *data)
{
	int i;
	int	tmp;
	int	longer;

	i = -1;
	tmp = 0;
	longer = 0;
	while (data->map[++i] != NULL)
	{
		tmp = ft_strlen(data->map[i]);
		if (tmp > longer)
			longer = tmp;
	}
	data->proportionality->y = (data->resolution_size->y / i);
	data->proportionality->x = (data->resolution_size->x / longer);
}

static	void	fill_player(t_config *data, char player_stance, int pos_y, int pos_x)
{
	if (data->player->dir_degree != 1.0f)
		catch_error(FILL_PLAYER_1);
	data->player->pos_player->x = pos_x;
	data->player->pos_player->y = pos_y;
	if (player_stance == 'E')
		data->player->dir_degree = 0.0f;
	if (player_stance == 'N')
		data->player->dir_degree = 90.0f;
	if (player_stance == 'W')
		data->player->dir_degree = 180.0f;
	if (player_stance == 'S')
		data->player->dir_degree = 270.0f;
	data->player->dir_radius = ((data->player->dir_degree * M_PI) / 180.0f);
}

void			check_border_player(t_config *data)
{
	int		countn;
	int		countn_one;
	int		i;

	i = -1;
	if (data->player->dir_degree == 1.0f)
		catch_error(CHECK_BORDER_PLAYER_1);
	while(data->map[++i + 1] != NULL)
	{
		countn = ft_strlen(data->map[i]) - 1;
		countn_one = ft_strlen(data->map[i + 1]) - 1;
		if (countn < countn_one)
			while (countn < countn_one)
			{
				if (data->map[i + 1][countn++] != '1')
					catch_error(CHECK_BORDER_PLAYER_2);
			}
		if (countn > countn_one)
			while (countn > countn_one)
			{
				if (data->map[i][countn_one++] != '1')
					catch_error(CHECK_BORDER_PLAYER_2);
			}
	}
	fill_proportionality(data);
}

char			*cube_map_parse(t_config *data, char *line, int line_counter)
{
	char	*formatedline;
	int		line_len;
	int		i;
	int		j;

	i = 0;
	j = -1;
	line_len = 0;
	if (line[0] != '1')
		catch_error(CUBE_MAP_PARSE_1);
	(ft_isonlycharset(line, " 012NSEW")) == SUCCESS ? 
		line_len = ft_strlen_without(line, ' ') : catch_error(CUBE_MAP_PARSE_2);
	formatedline = (char*)ft_memalloc(sizeof(char) * (line_len + SENTINAL));
	if (formatedline == NULL)
		catch_error(CUBE_MAP_PARSE_3);
	while (line[i])
	{
		if (line[i] != ' ')
		{
			formatedline[++j] = line[i];
			if ((ft_ischar("NSEW", line[i])) == SUCCESS)
				fill_player(data, line[i], line_counter, j);
		}
		i++;
	}
	if (line[i - 1] != '1')
		catch_error(CUBE_MAP_PARSE_4);
	return (formatedline);
}
