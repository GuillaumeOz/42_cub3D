/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:38:57 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/24 23:18:17 by gozsertt         ###   ########.fr       */
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
		*resolution = create_vector2(ft_atoi(tab[0]), ft_atoi(tab[1]));//add negativ resolution protection
		ft_tab_free(tab);
		return (true);
	}
	else
		return (false);
}

bool parse_environement_color(t_game_engine *engine, char *descriptor, char *content)
{
	if (ft_strcmp(descriptor, "C") == 0)
		return (set_color_type(engine, CEILING, content));
	else if (ft_strcmp(descriptor, "F") == 0)
		return (set_color_type(engine, FLOOR, content));
	else
		return (false);
}

bool parse_environement_texture(t_game_engine *engine, char *descriptor, char *content)
{
	if (ft_strcmp(descriptor, "WE") == 0)
		return (set_texture_image(engine, west, content));
	else if (ft_strcmp(descriptor, "NO") == 0)
		return (set_texture_image(engine, north, content));
	else if (ft_strcmp(descriptor, "EA") == 0)
		return (set_texture_image(engine, east, content));
	else if (ft_strcmp(descriptor, "SO") == 0)
		return (set_texture_image(engine, south, content));
	else if (ft_strcmp(descriptor, "S") == 0)
		return (set_sprite_image(engine, content));
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

static char	*ft_strcut_test(char **s1, char delim)
{
	char	*tmp;
	char	*result;
	size_t	len;
	size_t	string_size;

	tmp = *s1;
	len = 0;
	string_size = 0;
	while (tmp[len] != '\0' && tmp[len] == delim)
		len++;
	while (tmp[len + string_size] != '\0' && tmp[len + string_size] != delim)
		string_size++;
	result = ft_strndup(tmp + len, string_size);
	// free(*s1);
	return (result);
}

void parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution)
{
	char	*descriptor;
	char	*content;
	size_t	i;

	content = NULL;
	while (is_engine_full(engine) == false && get_next_line(fd, &content) > 0)
	{
		descriptor = ft_strcut_test(&content, ' ');
		i = 0;
		// ft_printf(" %v \n", (int)resolution->x, (int)resolution->y);
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
	}
}
