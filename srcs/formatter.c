/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:39:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/09 17:54:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void			free_buff(char ***to_free, int index)
{
	int i;

	i = -1;
	while (++i < index)
	{
		free((*to_free)[i]);
		free((*to_free));
	}
	catch_error("Malloc_formatter error 1");
}

static	int	check_map(t_data *data, char **file_ouput, int index)
{
	
}

t_config			*formatter(char *title)
{
	t_config	*data;
	char	**file_output;
	int		fd;
	int		ret;
	int		i;

	data = malloc_map_data();
	data->title = ft_strdup(title);ft_strndupfree
	fd = open("../map.cub", O_RDONLY);
	file_output = NULL;
	while (ret != 0)
	{
		file_output[i] = (char*)malloc(sizeof(char));
		if (file_output[i] == NULL)
			destroy_buff(&file_output, i);
		ret = get_next_line(fd, (&file_output)[i]);
		if (ret == -1)
			destroy_buff(&file_output, i);
		i++;
	}
	(check_map(data, file_output, i)) == SUCCESS ?
		data = parse_map(data, file_output, i) : destroy_buff(&file_output, i);
	data = parse_parameters(data, file_output, i);
	return (data);
}
