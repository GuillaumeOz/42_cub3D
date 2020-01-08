/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:38:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/07 13:45:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_map	*malloc_map_data(void)
{
	t_map	*map_data;

	map_data = (t_map *)malloc(sizeof(t_map));
	if (map_data == NULL)
		return (NULL);
	*map_data = create_map_data();
	return (map_data);
}

t_map	create_map_data(void)
{
	t_map	*map_data;

	*(map_data)->resolution_size = create_vector(0, 0);
	map_data->north_texture = ft_strnew(0);
	map_data->south_texture = ft_strnew(0);
	map_data->west_texture = ft_strnew(0);
	map_data->east_texture = ft_strnew(0);
	map_data->sprite_texture = ft_strnew(0);
	map_data->floor = malloc_color(0, 0, 0);
	map_data->ceiling = malloc_color(0, 0 ,0);
	map_data->map = NULL;
	return (*map_data);
}

void	destroy_map_data(t_map to_destroy)
{
	free_vector(&(to_destroy.resolution_size));
	free(to_destroy.north_texture);
	free(to_destroy.south_texture);
	free(to_destroy.west_texture);
	free(to_destroy.east_texture);
	free(to_destroy.sprite_texture);
	free_color(&(to_destroy.floor));
	free_color(&(to_destroy.ceiling));
	free_map(to_destroy.map); // finish this line
}

void	free_map_data(t_map *to_free)
{
	destroy_map_data (*to_free);
	free(to_free);
}
