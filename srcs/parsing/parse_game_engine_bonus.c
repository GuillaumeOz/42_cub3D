/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_engine_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:31:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 18:24:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_monster_image(t_game_engine *engine, char *path)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (engine->monster.life.path != NULL || engine->monster.dead.path != NULL)
		destroy_monster(engine->monster);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_MONSTER_IMAGE_1);
	while (path[i + j] != ' ')
		j++;
	while (path[i + j] == ' ')
		j++;
	path[i + j - 1] = '\0';
	while (path[i + j + k] != ' ')
		k++;
	path[i + j + k] = '\0';
	engine->monster = create_monster(ft_strdup(path + i),
					ft_strdup(path + i + j), ft_atoi(path + i + j + k + 1));
	engine->valid = ft_strprepend(engine->valid, "M", 1 , 0);
	return (true);
}

bool	set_medikit_image(t_game_engine *engine, char *path)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_MEDIKIT_IMAGE_1);
	if (engine->medikit.tex.path != NULL)
		destroy_medikit(engine->medikit);
	while (path[i + j] && path[i + j] != ' ')
		j++;
	if (path[i + j] == '\0')
		catch_error(SET_MEDIKIT_IMAGE_1);
	path[j + i] = '\0';
	engine->medikit = create_medikit(ft_strdup(path + i),
													ft_atoi(path + j + i + 1));
	engine->valid = ft_strprepend(engine->valid, "H", 1 , 0);
	return (true);
}

bool	set_door_image(t_game_engine *engine, char *path)
{
	int i;

	i = 0;
	if (engine->door.path != NULL)
		destroy_texture(engine->door);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_DOOR_IMAGE_1);
	engine->door = create_texture(ft_strdup(path + i));
	engine->valid = ft_strprepend(engine->valid, "3", 1 , 0);
	return (true);
}

bool	set_level_image(t_game_engine *engine, char *path)
{
	int i;

	i = 0;
	if (engine->secret.path != NULL)
		destroy_texture(engine->secret);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_LEVEL_IMAGE_1);
	engine->secret = create_texture(ft_strdup(path + i));
	engine->valid = ft_strprepend(engine->valid, "4", 1 , 0);
	return (true);
}
