/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_engine_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:31:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/10 14:59:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_monster_image(t_game_engine *engine, char *path)
{
	t_vector3	i;

	i = create_vector3(0, 0, 0);
	if (engine->monster.life.path != NULL || engine->monster.dead.path != NULL)
		catch_error(SET_MONSTER_IMAGE_1);
	while (path[(int)i.x] && path[(int)i.x] == ' ')
		i.x += 1;
	while (path[(int)i.x + (int)i.y] && path[(int)i.x + (int)i.y] != ' ')
		i.y += 1;
	while (path[(int)i.x + (int)i.y] && path[(int)i.x + (int)i.y] == ' ')
		i.y += 1;
	path[(int)i.x + (int)i.y - 1] = '\0';
	while (path[(int)i.x + (int)i.y + (int)i.z] && 
	path[(int)i.x + (int)i.y + (int)i.z] != ' ')
		i.z += 1;
	if (path[(int)i.x + (int)i.y + (int)i.z] == '\0')
		catch_error(SET_MONSTER_IMAGE_2);
	path[(int)i.x + (int)i.y + (int)i.z] = '\0';
	if ((ft_strisdigit(path + (int)i.x + (int)i.y + (int)i.z + 1) == false ||
	ft_atoi(path + (int)i.x + (int)i.y + (int)i.z + 1) < 0))
		catch_error(SET_MONSTER_IMAGE_2);
	engine->monster = create_monster(path + (int)i.x, path + (int)i.x +
	(int)i.y, ft_atoi(path + (int)i.x + (int)i.y + (int)i.z + 1));
	engine->valid = ft_strprepend(engine->valid, "M", 1, 0);
	return (true);
}

bool	set_medikit_image(t_game_engine *engine, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (engine->medikit.tex.path != NULL)
		catch_error(SET_MEDIKIT_IMAGE_2);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_MEDIKIT_IMAGE_1);
	while (path[i + j] && path[i + j] != ' ')
		j++;
	if (path[i + j] == '\0')
		catch_error(SET_MEDIKIT_IMAGE_1);
	path[j + i] = '\0';
	if ((ft_strisdigit(path + j + i + 1) == false ||
		ft_atoi(path + j + i + 1) < 0))
		catch_error(SET_MEDIKIT_IMAGE_1);
	engine->medikit = create_medikit(path + i, ft_atoi(path + j + i + 1));
	engine->valid = ft_strprepend(engine->valid, "H", 1, 0);
	return (true);
}

bool	set_door_image(t_game_engine *engine, char *path)
{
	int i;

	i = 0;
	if (engine->door.path != NULL)
		catch_error(SET_DOOR_IMAGE_1);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_DOOR_IMAGE_2);
	engine->door = create_texture(path + i);
	engine->valid = ft_strprepend(engine->valid, "3", 1, 0);
	return (true);
}

bool	set_secret_image(t_game_engine *engine, char *path)
{
	int i;

	i = 0;
	if (engine->secret.path != NULL)
		catch_error(SET_LEVEL_IMAGE_1);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_LEVEL_IMAGE_2);
	engine->secret = create_texture(path + i);
	engine->valid = ft_strprepend(engine->valid, "4", 1, 0);
	return (true);
}

bool	set_thread_option(t_game_engine *engine)
{
	if (engine->thread == true)
		catch_error(SET_THREAD_OPTION_1);
	engine->thread = true;
	return (true);
}
