/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:38:57 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/10 15:01:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_resolution(char *descriptor, char *content, t_vector2 *resolution)
{
	char	**tab;
	int		i;

	if (ft_strcmp(descriptor, "R") == 0)
	{
		if ((int)resolution->x != 0 && (int)resolution->y != 0)
			catch_error(PARSE_RESOLUTION_1);
		content++;
		tab = ft_split(content, ' ');
		if (ft_tab_len(tab) != 2)
			catch_error(PARSE_RESOLUTION_2);
		i = -1;
		while (tab[++i] != NULL)
			if (ft_strisdigit(tab[i]) == false)
				catch_error(PARSE_RESOLUTION_3);
		*resolution = create_vector2((ft_strlen(tab[0]) >= 10 ?
			2147483646 : ft_atoi(tab[0])), (ft_strlen(tab[1]) >= 10 ?
			2147483646 : ft_atoi(tab[1])));
		get_resolution(resolution);
		ft_tab_free(tab);
		return (true);
	}
	return (false);
}

bool	parse_environement_color(t_game_engine *engine,
	char *descriptor, char *content)
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

bool	parse_environement_texture(t_game_engine *engine,
	char *descriptor, char *content)
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
	else if (ft_strcmp(descriptor, "D") == 0)
		return (set_door_image(engine, content + 1));
	else if (ft_strcmp(descriptor, "H") == 0)
		return (set_medikit_image(engine, content + 1));
	else if (ft_strcmp(descriptor, "M") == 0)
		return (set_monster_image(engine, content + 1));
	else if (ft_strcmp(descriptor, "L") == 0)
		return (set_secret_image(engine, content + 1));
	else if (ft_strcmp(descriptor, "T") == 0)
		return (set_thread_option(engine));
	else
		return (false);
}

bool	is_engine_full(t_game_engine *engine, t_vector2 *resolution)
{
	if (resolution->x == 0 || resolution->y == 0 ||
		engine->texture[0] == NULL || engine->texture[1] == NULL ||
		engine->texture[2] == NULL || engine->texture[3] == NULL ||
		engine->ceiling == NULL || engine->floor == NULL ||
		engine->sprite == NULL)
		return (false);
	return (true);
}

void	parse_game_engine(t_game_engine *engine, int fd, t_vector2 *res)
{
	char	*id;
	char	*content;
	size_t	i;

	content = NULL;
	while (is_engine_full(engine, res) == false &&
		get_next_line(fd, &content) > 0)
	{
		id = ft_strcut(&content, ' ');
		i = 0;
		while (content[i] != '\0' && content[i] == ' ')
			i++;
		if (parse_environement_texture(engine, id, &(content[i])) == true)
			;
		else if (parse_environement_color(engine, id, &(content[i])) == true)
			;
		else if (parse_resolution(id, &(content[i]), res) == true)
			;
		else if (ft_strlen(id) == 0)
			;
		else
			catch_error(PARSE_GAME_ENGINE_1);
		free(id);
		free(content);
	}
}
