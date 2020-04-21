/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:41:26 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/21 15:32:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	set_texture_image(t_game_engine *engine, t_direction dir, char *path)
{
	int i;

	i = 0;
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_TEXTURE_IMAGE_1);
	engine->texture[(int)(dir)] = malloc_texture(path + i);
	return (true);
}

bool	set_sprite_image(t_game_engine *engine, char *path)
{
	int i;

	i = 0;
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_SPRITE_IMAGE_1);
	engine->sprite = malloc_texture(path + i);
	return (true);
}

bool	set_color_type(t_game_engine *engine, int type, char *content)
{
	size_t	i;
	char	**tab;
	t_color *color;

	if ((type == CEILING && engine->ceiling != NULL) ||
		(type == FLOOR && engine->floor != NULL))
		catch_error(SET_COLOR_TYPE_1);
	tab = ft_split(content, ',');
	if (ft_tab_len(tab) != 3)
		catch_error(SET_COLOR_TYPE_2);
	i = 0;
	while (tab[i] != NULL)
	{
		if ((ft_strisdigit(tab[i])) == false)
			catch_error(SET_COLOR_TYPE_3);
		i++;
	}
	color = malloc_color(ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]), 255);
	ft_tab_free(tab);
	if (type == CEILING)
		engine->ceiling = color;
	else if (type == FLOOR)
		engine->floor = color;
	return (true);
}
