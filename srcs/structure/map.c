/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 14:11:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 15:26:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**malloc_map(int map_x, int map_y)
{
	char	**map;
	size_t	i;

	i = -1;
	if (map_y < 1 || map_x < 1)
		return (NULL);
	while (++i < map_y)
	{
		map = (char**)malloc(sizeof(char*));
		if (map == NULL)
			return (NULL); //use gnl here
		create_map(map_x, map[i]);
	}
	
}

char	create_map(int map_x, int map_y)
{
	map[i] = ((char*)malloc((sizeof(char)) * map_x));//use gnl here
}

void	destroy_map(char to_destroy)
{
	
}

void	free_map(char **to_free)
{
	
}
