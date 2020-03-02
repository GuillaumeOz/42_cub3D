/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:38:57 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/02 12:50:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool parse_resolution(char *descriptor, char *content, t_vector2 *resolution)
{
	char **tab;
	size_t i;

	if (ft_strcmp(descriptor, "R") == 0)
	{
		content++;
		tab = ft_split(content, ' ');
		if (ft_tab_len(tab) != 2)
			catch_error(PARSE_RESOLUTION_1);
		i = 0;
		while (tab[i] != NULL)
		{
			if (ft_strisdigit(tab[i]) == false)
				catch_error(PARSE_RESOLUTION_2);
			i++;
		}
		if (ft_atoi(tab[0]) < 0 || ft_atoi(tab[1]) < 0 || 
			ft_atoi(tab[0]) > 2560 || ft_atoi(tab[1]) > 1440)
			catch_error(PARSE_RESOLUTION_3);
		*resolution = create_vector2(ft_atoi(tab[0]), ft_atoi(tab[1]));
		ft_tab_free(tab);
		return (true);
	}
	else
		return (false);
}

bool parse_environement_color(t_game_engine *engine, char *descriptor, char *content)
{
	int i;

	i = 1;
	if (ft_strcmp(descriptor, "C") == 0)
	{
		while (content[i] && content[i] == ' ')
			i++;
		if (content[i] == '\0')
			catch_error(PARSE_ENVIRONEMENT_COLOR_1);
		return (set_color_type(engine, CEILING, content + i));
	}
	else if (ft_strcmp(descriptor, "F") == 0)
	{
		while (content[i] && content[i] == ' ')
			i++;
		if (content[i] == '\0')
			catch_error(PARSE_ENVIRONEMENT_COLOR_2);
		return (set_color_type(engine, FLOOR, content + i));
	}
	else
		return (false);
}

bool parse_environement_texture(t_game_engine *engine, char *descriptor, char *content)
{
	if (ft_strcmp(descriptor, "WE") == 0)
		return (set_texture_image(engine, west, content + 2));
	else if (ft_strcmp(descriptor, "NO") == 0)
		return (set_texture_image(engine, north, content + 2));
	else if (ft_strcmp(descriptor, "EA") == 0)
		return (set_texture_image(engine, east, content + 2));
	else if (ft_strcmp(descriptor, "SO") == 0)
		return (set_texture_image(engine, south, content + 2));
	else if (ft_strcmp(descriptor, "S") == 0)
		return (set_sprite_image(engine, content + 1));
	else
		return (false);
}

bool is_engine_full(t_game_engine *engine)
{
	if (engine->texture[0] == NULL || engine->texture[1] == NULL ||
		engine->texture[2] == NULL || engine->texture[3] == NULL ||
		engine->ceiling == NULL || engine->floor == NULL)
		return (false);
	return (true);
}

void parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution)
{
	char	*descriptor;
	char	*content;
	size_t	i;

	content = NULL;
	while (is_engine_full(engine) == false && get_next_line(fd, &content) > 0)
	{
		descriptor = ft_strcut(&content, ' ');
		i = 0;
		while (content[i] != '\0' && content[i] == ' ')
			i++;
		if (parse_environement_texture(engine, descriptor, &(content[i])) == true)
			;
		else if (parse_environement_color(engine, descriptor, &(content[i])) == true)
			;
		else if (parse_resolution(descriptor, &(content[i]), resolution) == true)
			;
		else if (ft_strlen(descriptor) == 0)
			;
		else
			catch_error(PARSE_GAME_ENGINE_1);
		free(descriptor);
		free(content);
	}
}
