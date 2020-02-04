/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:38:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/09 17:37:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_config	*malloc_config(void)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (config == NULL)
		return (NULL);
	*config = create_config();
	return (config);
}

t_config	create_config(void)
{
	t_config	config;

	config.title =  NULL;
	config.player = malloc_player(0.0f, 0.0f, 1.0f, 0.0f);
	config.resolution_size = malloc_vector(0.0f, 0.0f);
	config.north_texture = NULL;
	config.south_texture = NULL;
	config.west_texture = NULL;
	config.east_texture = NULL;
	config.sprite_texture = NULL;
	config.floor = malloc_color(0, 0, 0, 255);
	config.ceiling = malloc_color(0, 0, 0, 255);
	config.map = NULL;
	return (config);
}

void	free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL) // keep this function ?
		free(map[i]);
	free(map);
}

void	destroy_config(t_config to_destroy)
{
	free(to_destroy.title);
	free_vector(to_destroy.resolution_size);
	free_player(to_destroy.player);
	free(to_destroy.north_texture);
	free(to_destroy.south_texture);
	free(to_destroy.west_texture);
	free(to_destroy.east_texture);
	free(to_destroy.sprite_texture);
	free_color(to_destroy.floor);
	free_color(to_destroy.ceiling);
	free_map(to_destroy.map);
}

void	free_config(t_config *to_free)
{
	destroy_config (*to_free);
	free(to_free);
}
